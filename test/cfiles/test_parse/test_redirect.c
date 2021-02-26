#ifdef OPEN_REDIR_FILE
// update_redir_configのテストも兼任
#include <wait.h>
#include <errno.h>
#include "constants.h"
#include "parse.h"
#include "struct/redir_mode.h"
#include "struct/process.h"
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "utils.h"
#include "libft.h"

static void	test_open(char *str, t_redir_mode *redir_mode)
{
	char buf[1000];
	t_process redir_config;
	char	*fname_expanded;
	char	*filename;
	
	fname_expanded = ft_strdup(str);
	filename = ft_strdup(str);
	ft_bzero(&redir_config, sizeof(t_process));
	update_redir_config(&redir_config, filename, redir_mode);
	if (open_redir_file(str, &redir_config, redir_mode) == ERROR)
		p_open_err(NULL, NULL, fname_expanded, &redir_config);
	else
	{
		free(fname_expanded);
		free(filename);
		sprintf(buf, "cat %s", str);
		system(buf);
		wait(NULL);
	}
}

int		main(void)
{
	char* add_out[] = {
		"test/var/exist",
		"test/var/add",
	};
	char* append_out = "test/var/append";
	char* in = "test/var/in";
	char* errout = "test/var/errout";
	char* bad_in[] = {
		"test/var/no_permission",
		"test/var/no_read",
		"notexist",
		"test/var/notexist",
	};
	char* bad_out[] = {
		"test/var/no_write",
		"test/var/no_permission",
	};
	t_redir_mode	redir_mode;
	char	buf[1000];

	system("chmod a-r test/var/no_read"); wait(NULL);
	system("chmod 000 test/var/no_permission"); wait(NULL);

	redir_mode.mode_bit = REDIR_OUT;
	ft_putstr_fd("======= stdout add ========\n", STD_OUT);
	for (unsigned int i = 0; i < sizeof(add_out) / sizeof(char*) ; i++)
		test_open(add_out[i], &redir_mode);
	system("ls test/var"); wait(NULL);

	redir_mode.mode_bit = REDIR_OUT | REDIR_APPEND;
	ft_putstr_fd("======= stdout append ========\n", STD_OUT);
	test_open(append_out, &redir_mode);
	system("ls test/var"); wait(NULL);

	redir_mode.mode_bit = REDIR_IN;
	ft_putstr_fd("======= stdin ========\n", STD_OUT);
	test_open(in, &redir_mode);
	system("ls test/var"); wait(NULL);

	redir_mode.mode_bit = REDIR_ERR;
	ft_putstr_fd("======= stderr ========\n", STD_OUT);
	test_open(errout, &redir_mode);
	system("ls test/var"); wait(NULL);

	redir_mode.mode_bit = REDIR_IN;
	ft_putstr_fd("======= bad in ========\n", STD_OUT);
	for (unsigned int i = 0; i < sizeof(bad_in) / sizeof(char*); i++)
		test_open(bad_in[i], &redir_mode);
	system("ls test/var"); wait(NULL);

	redir_mode.mode_bit = REDIR_OUT;
	ft_putstr_fd("======= bad out ========\n", STD_OUT);
	for (unsigned int i = 0; i < sizeof(bad_out) / sizeof(char*); i++)
		test_open(bad_out[i], &redir_mode);
	system("ls test/var"); wait(NULL);

	system("rm test/var/add"); wait(NULL);
	system("echo exist > test/var/exist"); wait(NULL);
	sprintf(buf, "rm %s", errout);
	system(buf); wait(NULL);
	system("chmod a+r test/var/no_read"); wait(NULL);
	system("chmod 744 test/var/no_permission"); wait(NULL);
}

#endif

#ifdef IS_JUDGE_FUNCS_C
#include <stdio.h>
#include "parse.h"


int		main(void)
{
	char*	correct[] = {
		"  aaaa  ",
		"aaa",
		"\"  hoge  \"",
		"  ' a a a '  ",
		"  aa\" \\\" a a \"aa  ",
		"  aa\\ a\\a\\ a  ",
	};
	char*	wrong[] = {
		"a a",
		"    a a    ",
		"   a\ta  ",
		"  \"\" ''",
	};
	for (unsigned int i = 0; i < sizeof(correct) / sizeof(char*); i++)
	{
		printf("%d: result[%d]\n", i, is_ambiguous_err(correct[i]));
		if (is_ambiguous_err(correct[i]))
			printf("unexpected result at %d\n", i);
	}
	for (unsigned int i = 0; i < sizeof(wrong) / sizeof(char*); i++)
	{
		printf("%d: result[%d]\n", i, is_ambiguous_err(wrong[i]));
		if (!is_ambiguous_err(wrong[i]))
			printf("unexpected result at %d\n", i);
	}
}

#endif

#ifdef FILL_SPACE_C
#include "parse.h"
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int		main(void)
{
	char* examples1[] = {
		">a this is",							"example",
		"left  >hoge  right",				"left         right",
		">  hoge  ",						"         ",
		"> hoge>a",							"      >a",
		"2>hoge<a",							"      <a",
		"1<hoge<a",							"      <a",
		"< \"hoge\" a",						"         a",
		"left 0<hoge\tright",				"left       \tright",
		"left<\t\thoge\tright",				"left \t\t    \tright",	
		"left<'   hoge   ' right",			"left              right",
		"left0<\"'   hoge   '\" right",		"left0                right",
		"left< hoge\\ a right",				"left          right",
		"left<\" hoge\\\" a\" right",		"left             right",
		"a 2>>hoge<hoge",					"a        <hoge",
		"left>>  hoge  right",				"left          right",
		"left 1>> hoge>rigth",				"left         >rigth",
		"left>>hoge<a",						"left      <a",
	};
	char *raw_redir_filename;
	char *str_proc;
	t_redir_mode	redir_mode;

	for (unsigned int i = 0; i < sizeof(examples1) / sizeof(char*); i += 2)
	{
		int redir_idx;
		for (redir_idx = 0; examples1[i][redir_idx] != '<' && examples1[i][redir_idx] != '>'; redir_idx++) {;}

		str_proc = ft_strdup(examples1[i]);
		detect_redir_mode(str_proc, redir_idx, &redir_mode);
		raw_redir_filename =
			get_redirect_file(examples1[i], redir_idx, redir_mode.mode_bit);
		fill_space(str_proc, redir_idx, &redir_mode, raw_redir_filename);

		printf("%d [%s] : [%s]\n", i / 2, str_proc, examples1[i + 1]);
		if (strcmp(str_proc, examples1[i + 1]))
			printf("result differs at %d\n\n", i / 2);
		free(redir_mode.fd_str);
		free(str_proc);
		free(raw_redir_filename);
	}
}

#endif

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
