#ifdef GET_REDIRECT_FILE_C
#include <string.h>
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	char *raw_redir_filename;
	char* examples1[] = {
		">ThisIs",				"example",
		">hoge",				"hoge",
		">  hoge  ",			"hoge",
		"> hoge>a",				"hoge",
		">hoge<a",				"hoge",
		"<hoge<a",				"hoge",
		"< \"hoge\"",			"\"hoge\"",
		"<hoge\t",				"hoge",
		"<\t\thoge\t",			"hoge",
		"<'   hoge   '",		"'   hoge   '",
		"<\"'   hoge   '\"",	"\"'   hoge   '\"",
		"< hoge\\ a",			"hoge\\ a",
		"<\" hoge\\\" a\"",		"\" hoge\\\" a\"",
	};
	char* examples2[] = {
		">>hoge",			"hoge",
		">>  hoge  ",		"hoge",
		">> hoge>a",		"hoge",
		">>hoge<a",			"hoge",
	};
	for (unsigned int i = 0; i < sizeof(examples1) / sizeof(char*); i += 2)
	{
		raw_redir_filename = get_redirect_file(examples1[i], 0, REDIR_OUT | REDIR_IN);
		if (strcmp(raw_redir_filename, examples1[i + 1]))
			printf("ex1 result differs at %d [%s : %s]\n", i / 2, raw_redir_filename, examples1[i + 1]);
		free(raw_redir_filename);
	}
	for (unsigned int i = 0; i < sizeof(examples2) / sizeof(char*); i += 2)
	{
		raw_redir_filename = get_redirect_file(examples2[i], 0, REDIR_OUT | REDIR_APPEND);
		if (strcmp(raw_redir_filename, examples2[i + 1]))
			printf("ex2 result differs at %d [%s : %s]\n", i / 2, raw_redir_filename, examples2[i + 1]);
		free(raw_redir_filename);
	}
}

#endif

#ifdef DETECT_REDIR_MODE_C
#include "struct/redir_mode.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

static void	test_get_redmode(char *str, t_redir_mode *redir_mode)
{
	int j;
	for (j = 0; str[j] && str[j] != '<' && str[j] != '>'; j++) {;}
	detect_redir_mode(str, j, redir_mode);
}

int		main(void)
{
	t_redir_mode	redir_mode;
	char*	out1[] = {
		">",
		" >",
		"a>",
		" >>",
	};
	char*	out2[] = {
		"1>a",
		" 1>a",
		" 1>>a",
	};
	char*	in1[] = {
		"<",
		" <",
		"a <",
		"a a<",
	};
	char*	in2[] = {
		"0<",
		"a 0<",
		"a 0<",
	};
	char*	err1[] = {
		"2>",
		" 2>",
		"a 2>",
		"a 2>>",
	};
	char*	append[] = {
		" 1>>a",
		"a 2>>",
		" >>",
	};
	char*	badfd[] = {
		///// bad fd below
		"112>",		"112",
		"1<",		"1",
		"2<",		"2",
		"10<",		"10",
		"3>",		"3",
		"3>>",		"3",
		"11>>",		"11",
		"12>>",		"12",
		"02>", 		"02"// 本家では2として出力されるが、エラーとして処理する
	};

	for (size_t i = 0; i < sizeof(out1) / sizeof(char*); i++)
	{
		test_get_redmode(out1[i], &redir_mode);
		if (!(redir_mode.mode_bit & REDIR_OUT))
			printf("out 1 failure at %ld, %x\n", i, redir_mode.mode_bit);
		free(redir_mode.fd_str);
	}
	for (size_t i = 0; i < sizeof(out2) / sizeof(char*); i++)
	{
		test_get_redmode(out2[i], &redir_mode);
		if (! ((redir_mode.mode_bit & REDIR_OUT) && !strcmp(redir_mode.fd_str, "1")))
			printf("out 2 failure at %ld\n", i);
		free(redir_mode.fd_str);
	}
	for (size_t i = 0; i < sizeof(in1) / sizeof(char*); i++)
	{
		test_get_redmode(in1[i], &redir_mode);
		if (! (redir_mode.mode_bit & REDIR_IN) )
			printf("in 1 failure at %ld\n", i);
		free(redir_mode.fd_str);
	}
	for (size_t i = 0; i < sizeof(in2) / sizeof(char*); i++)
	{
		test_get_redmode(in2[i], &redir_mode);
		if (! ((redir_mode.mode_bit & REDIR_IN) && !strcmp(redir_mode.fd_str, "0")))
			printf("in 2 failure at %ld\n", i);
		free(redir_mode.fd_str);
	}
	for (size_t i = 0; i < sizeof(err1) / sizeof(char*); i++)
	{
		test_get_redmode(err1[i], &redir_mode);
		if (! ((redir_mode.mode_bit & REDIR_ERR) && !strcmp(redir_mode.fd_str, "2")))
			printf("err1 failure at %ld\n", i);
		free(redir_mode.fd_str);
	}
	for (size_t i = 0; i < sizeof(append) / sizeof(char*); i++)
	{
		test_get_redmode(append[i], &redir_mode);
		if (! (redir_mode.mode_bit & REDIR_APPEND))
			printf("append failure at %ld\n", i);
		free(redir_mode.fd_str);
	}
	for (size_t i = 0; i < sizeof(badfd) / sizeof(char*); i += 2)
	{
		test_get_redmode(badfd[i], &redir_mode);
		// printf("%s : %s \n", redir_mode.fd_str, badfd[i + 1]);
		if (strcmp(redir_mode.fd_str, badfd[i + 1]))
			printf("invalid result at %ld\n", i / 2);
		if (! (redir_mode.mode_bit & REDIR_BAD_FD))
			printf("badfd failure at %ld\n", i);
		free(redir_mode.fd_str);
	}
}
#endif
