#include "builtins/builtins.h"

#ifdef MY_EXPORT_C

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"

void test_my_export(char **args, int n)
{
	int i;
	char **allocated_arg;
	// char *simple_export[] = {"export", NULL};

	pendl();
	ft_putnbr_fd(n, STD_OUT);
	ft_putstr_fd(" ====================\n", STD_OUT);
	allocated_arg = ft_calloc(sizeof(char*), count_string_arr_row(args) + 1);
	for(i = 0; args[i]; ++i)
		allocated_arg[i] = ft_strdup(args[i]);
	allocated_arg[i] = NULL;
	my_export(allocated_arg);
	// my_export(simple_export);
}

int main(int argc, char *argv[], char *envp[])
{
	char *args1[] = {"export", "foo=foo1", NULL};
	char *args2[] = {"export", "hoge=hoge", NULL};
	char *args3[] = {"export", "foo=foo3", NULL};
	char *args4[] = {"export", "foo=foo5", "hoge=hoge5", NULL};
	char *args5[] = {"export", "hello=\\h\\\"el$lo", NULL};

	char *args11[] = {"export", "ava", NULL};
	char *args12[] = {"export", "ava=ava", NULL};

	char *args13[] = {"export", "hoge=hoge13", NULL};
	char *args14[] = {"export", "hoge", NULL};

	// =が複数の時
	char *args15[] = {"export", "a=a=a", NULL};

	// 不当なkey
	char *args21[] = {"export", "$=dollar", NULL};
	char *args22[] = {"export", "aaa$=aaa", NULL};
	char *args23[] = {"export", "==a", NULL}; //error出力
	char *args24[] = {"export", "\"=a", NULL}; //error出力
	char *args25[] = {"export", "'=a", NULL}; //error出力
	char *args26[] = {"export", "$=a", NULL}; //error出力
	char *args27[] = {"export", "a =a", NULL}; //error出力
	char *args28[] = {"export", " a=a", NULL}; //error出力
	char *args29[] = {"export", "]=a", NULL}; //error出力
	char *args31[] = {"export", "=a=a", NULL}; //error出力


	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	test_my_export(args1, 1);
	test_my_export(args2, 2);
	test_my_export(args3, 3);
	test_my_export(args4, 4);
	test_my_export(args5, 5);

	test_my_export(args11, 11);
	test_my_export(args12, 12);
	test_my_export(args13, 13);
	test_my_export(args14, 14);

	test_my_export(args15, 30);

	test_my_export(args21, 21);
	test_my_export(args22, 22);

	test_my_export(args23, 23);
	test_my_export(args24, 24);
	test_my_export(args25, 25);
	test_my_export(args26, 26);
	test_my_export(args27, 27);
	test_my_export(args28, 28);
	test_my_export(args29, 29);
	test_my_export(args31, 31);
}

#endif

#ifdef MY_ECHO_C 

int main(void)
{
	char *args[]= {"echo", "hello1", NULL};
	char *args2[] = {"echo", "-nn", NULL};
	char *args3[] = {"echo", "-nnnnnnn", "3", NULL};
	char *args4[] = {"echo", "-nnnnnnn", "4", NULL};
	char *args5[] = {"echo", "-n", "-n", "-n", "5", NULL};
	char *args6[] = {"echo", "-n", "-n", "6", "6", NULL};
	char *args7[] = {"echo", "-n4", NULL};
	char *args8[] = {"echo", "-n!", NULL};
	char *args9[] = {"echo", "-n", NULL};
	char *args10[] = {"echo", "-n", "world10", NULL};
	char *args11[] = {"echo", "-n", "hello11", "world", NULL};

	char *args12[] = {"echo", "hoge", "\\n", NULL};
	char *args13[] = {"echo", "hoge", "fuga", NULL};

	char *args14[] = {"echo", NULL};

	char *args15[] = {"echo", "hello", "-n", NULL};

	my_echo(args);
	my_echo(args2);
	my_echo(args3);
	my_echo(args4);
	my_echo(args5);
	my_echo(args6);
	my_echo(args7);
	my_echo(args8);
	my_echo(args9);
	my_echo(args10);
	my_echo(args11);
	my_echo(args12);
	my_echo(args13);
	my_echo(args14);
	my_echo(args15);
}

#endif
