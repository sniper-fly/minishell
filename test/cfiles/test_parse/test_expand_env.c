#ifdef EXPAND_ENV_VAR_STR_C
#include <signal.h>
#include "parse.h"
#include "env_ctrl.h"
#include "builtins/builtins.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char	**environ;
extern volatile sig_atomic_t g_status;

static void	print_result(char *str, char *answer, int i)
{
	char	*expanded;

	expanded = expand_env_var_str(str);
	printf("[%d] : %s : %s\n", i / 2, str, expanded);
	if (strcmp(expanded, answer) != 0)
		printf("!!not expected result at %d answer is[%s]\n\n", i / 2, answer);
	free(expanded);
}

static void	leak_test(void)
{
	//左が変換前、右が変換後の想定文字列
	char*	tests[] = {
		"normal char", 		"normal char",
		"[$ ]",				"[$ ]",
		"[$\\]",			"[$\\]",
		"[$}]",				"[$}]",
		"$", 				"$",
		"$$$", 				"$$$",
		"$\\$$", 			"$\\$$",
		"hello $name !", 	"hello nop !",
		"$name$name",		"nopnop",
		"$name\\aaa$foo", 	"nop\\aaabar",
		"notexist$notexist","notexist",
		"$foo$notexist",	"bar",
		"$\"foo\"$notexist","\"foo\"",
		"$'foo'$notexist", 	"'foo'",
		"$?aa", 			"42aa",
		"$?aa$?", 			"42aa42",
		"$$foo",			"$bar",
		"\"$foo\"$name",	"\"bar\"nop",
		"'$foo'$name",		"'$foo'nop",
		"foo\\$foo",		"foo\\$foo",
		"$$$$$foo",			"$$$$bar",
		"\"'$foo'\"",		"\"'bar'\"",
		"\"\\\"'$foo'\\\"\"\0",	"\"\\\"'bar'\\\"\"\0", //"\"'$foo'\""
		"\"$\"",			"\"$\"",
		"\"$'\"",			"\"$'\"",
		"'$'",				"'$'",
		"$\"\"",			"\"\"",
		"\" $\\ \"",		"\" $\\ \"", //" $\ "
		"'$'",				"'$'",
		"\"$}\"",			"\"$}\"",
		"\"$$\"",			"\"$$\"",
		"\" $$ \"",			"\" $$ \"",
		"\"$_a\"",			"\"\"",
		"\"$+a\"",			"\"$+a\"",
		"$+a",				"$+a",
		"\"$?\"",			"\"42\"",
		"\"$name+a\"",		"\"nop+a\"",
	};
	char*	env_to_add1[] = {"export", "name=nop", NULL};
	char*	env_to_add2[] = {"export", "foo=bar", NULL};
	create_env_list(environ);
	my_export(env_to_add1);
	my_export(env_to_add2);
	g_status = 42;
	for (unsigned int i = 0; i < sizeof(tests) / sizeof(char*); i += 2)
		print_result(tests[i], tests[i + 1], i);
}

int		main(void)
{
	leak_test();
}

#endif


#ifdef GET_SINGLE_ENV_KEY_C
#include "parse.h"
#include <stdio.h>
#include "libft.h"
#include "constants.h"
#include <stdlib.h>
#include "utils.h"

void	test_get_single_env_key(char *str, int idx)
{
	static int num = 1;
	char	*tmp = get_single_env_key(str, idx);

	ft_putnbr_fd(num, STD_OUT);
	pendl();
	ft_putendl_fd(tmp, STD_OUT);
	ft_putendl_fd("=============", STD_OUT);
	free(tmp);
	num++;
}

int		main(void)
{
	char str1[] = "$world";
	char str2[] = "$\"\"world";
	char str3[] = "$world$hoge";
	char str4[] = "$hey ";
	char str5[] = "$hey\t ";
	char str6[] = "a$hey\"";
	char str7[] = "ab$hey\\";
	char str8[] = "a$hey'";
	char str9[] = "$$hey'";
	char str10[] = "$hey+yo";
	char str11[] = "$hey_yo";
	char str12[] = "$hey$yo";

	test_get_single_env_key(str1, 1);
	test_get_single_env_key(str2, 1);
	test_get_single_env_key(str3, 1);
	test_get_single_env_key(str4, 1);
	test_get_single_env_key(str5, 1);
	test_get_single_env_key(str6, 2);
	test_get_single_env_key(str7, 3);
	test_get_single_env_key(str8, 2);
	test_get_single_env_key(str9, 2);
	test_get_single_env_key(str10, 1);
	test_get_single_env_key(str11, 1);
	test_get_single_env_key(str12, 1);
}

#endif

#ifdef AUTO_RESIZE_CPY_C
#include <stdlib.h>
#include "parse.h"
#include <stdio.h>
#include "libft.h"
#include <string.h>

static void leak_test_func1(void)
{
	char	*dst;
	char	src[] = "hello wo";
	int		buf_size;

	buf_size = 10;
	dst = ft_calloc(sizeof(char), buf_size);
	for (int i = 0; src[i]; i++)
		dst = auto_resize_cpy(dst, i, &buf_size, src[i]);
	ft_putendl_fd(dst, 1);
	free(dst);
}

static void leak_test_func2(void)
{
	char	*dst;
	char	src[] = "hello world hoge hey foo bar baz";
	int		buf_size;

	buf_size = 10;
	dst = ft_calloc(sizeof(char), buf_size);
	for (int i = 0; src[i]; i++)
		dst = auto_resize_cpy(dst, i, &buf_size, src[i]);
	ft_putendl_fd(dst, 1);
	free(dst);
}

void	leak_test_func3()
{
	char *src;
	char *dst;
	int		bufsize = 10;
	int		idx = 0;
	dst = ft_calloc(sizeof(char*), bufsize);
	src = ft_calloc(sizeof(char*), 20000);
	for (int i = 0; i < 10000; i++)
	{
		if (i % 10 == 0)
		{
			src[idx] = '\n';
			dst[idx] = '\n';
			idx++;
		}
		src[idx] = (i % 10) + '0';
		dst = auto_resize_cpy(dst, idx, &bufsize, (i % 10) + '0');
		idx++;
	}
	if (strcmp(src, dst))
		printf("cpy failed\n");
	// ft_putstr_fd(src, 1);
	// ft_putstr_fd(dst, 2);
	free(src);
	free(dst);
}

int		main(void)
{
	leak_test_func1();
	leak_test_func2();
	leak_test_func3();
}

#endif
