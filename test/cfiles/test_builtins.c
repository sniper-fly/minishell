#include "builtins/builtins.h"

#ifdef MY_EXPORT_C

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"

void test_my_export(char **args)
{
	int i;
	char **allocated_arg;
	char *simple_export[] = {"export", NULL};

	ft_putstr_fd("\n====================\n", STD_OUT);
	allocated_arg = malloc(sizeof(args));
	for(i = 0; args[i]; ++i)
		allocated_arg[i] = ft_strdup(args[i]);
	allocated_arg[i] = NULL;
	my_export(allocated_arg);
	// free_string_arr(allocated_arg);
	my_export(simple_export);
}

int main(int argc, char *argv[], char *envp[])
{
	char *args1[] = {"export", "foo=foo1", NULL};
	char *args2[] = {"export", "hoge=hoge", NULL};
	char *args3[] = {"export", "foo=foo3", NULL};
	char *args5[] = {"export", "foo=foo5", "hoge=hoge5", NULL};
	char *args7[] = {"export", "hoge=hoge", "foo=$hoge:foo", NULL};

	char *args11[] = {"export", "ava=", NULL};
	char *args12[] = {"export", "ava", NULL};


	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	test_my_export(args1);
	test_my_export(args2);
	test_my_export(args3);
	test_my_export(args4);
	test_my_export(args5);
	test_my_export(args6);
	test_my_export(args7);

	test_my_export(args10);
	test_my_export(args11);
	test_my_export(args12);
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
