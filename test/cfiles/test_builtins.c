#include "builtins/builtins.h"

#ifdef EXEC_BUILTINS_C

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "utils.h"
#include "libft.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/t_bool.h"
#include "struct/env_list.h"

static void test_exec_builtins(char **args, int n)
{
	pendl();
	ft_putnbr_fd(n, STD_OUT);
	ft_putendl_fd(" ==============================", STD_OUT);
	if(fork())
		wait(NULL);
	else
	{
		exec_builtins(args);
		exit(0);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char *args1[] = {"export", "foo=foo", NULL};
	char *args2[] = {"echo", "hello", "world", NULL};
	char *args3[] = {"pwd", NULL};
	char *args4[] = {"env", NULL};
	char *args5[] = {"cd", "src", NULL};
	char *args6[] = {"unset", "foo", NULL};
	char *args7[] = {"export", NULL};
	char *args8[] = {"exit", "1", NULL};

	char *args10[] = {"noexist", NULL};
	char *args11[] = {"valgrind", NULL};

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	test_exec_builtins(args1, 1);
	test_exec_builtins(args2, 2);
	test_exec_builtins(args3, 3);
	test_exec_builtins(args4, 4);
	test_exec_builtins(args5, 5);
	test_exec_builtins(args6, 6);
	test_exec_builtins(args7, 7);
	test_exec_builtins(args8, 8);

	test_exec_builtins(args10, 10);
	test_exec_builtins(args11, 11);

}

#endif

#ifdef MY_EXIT_C

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include "utils.h"
#include "libft.h"

static void test_my_exit(char **args, int n)
{
	int pid;
	int status;

	ft_putnbr_fd(n, 1);
	ft_putendl_fd(" ==========", 1);
	if((pid = fork()))
	{
		waitpid(pid, &status, 0);
		ft_putstr_fd("status: ", 1);
		ft_putnbr_fd(WEXITSTATUS(status), 1);
		pendl();
		pendl();
	}
	else
		my_exit(args);
}

int main(void)
{
	char *args1[] = {"exit", "0", NULL};
	char *args2[] = {"exit", "1", NULL};
	char *args3[] = {"exit", "1000", NULL};
	char *args4[] = {"exit", "-1", NULL};
	char *args5[] = {"exit", "-500", NULL};
	char *args6[] = {"exit", NULL};
	char *args7[] = {"exit", "1111111111111111111", NULL};	// 19ケタ

	char *args10[] = {"exit", "1", "2", "3", NULL};
	char *args11[] = {"exit", "11111111111111111111", NULL};	// 20ケタ

	test_my_exit(args1, 1);
	test_my_exit(args2, 2);
	test_my_exit(args3, 3);
	test_my_exit(args4, 4);
	test_my_exit(args5, 5);
	test_my_exit(args6, 6);
	test_my_exit(args7, 7);

	test_my_exit(args10, 10);
	test_my_exit(args11, 11);
}

#endif

#ifdef MY_PWD_C

#include "libft.h"
#include "env_ctrl.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

int main(int argc, char *argv[], char *envp[])
{
	char *pwd_args[] = {"pwd", NULL};
	char *cd_args[] = {"cd", "src", NULL};

	argc += 1;
	argv[0][0] = 'a';

	create_env_list(envp);

	my_pwd(pwd_args);
	my_cd(cd_args);
	my_pwd(pwd_args);
}

#endif

#ifdef MY_ENV_C

#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"

static void test_my_env(char **args, int n)
{
	ft_putnbr_fd(n, STD_OUT);
	ft_putendl_fd(" ==========", STD_OUT);

	my_env(args);
	pendl();
}

int main(int argc, char *argv[], char *envp[])
{
	char *args1[] = {"env", NULL};
	char *args2[] = {"env", "foo=foo2", NULL};
	char *args3[] = {"env", "foo=foo3", "hoge=hoge3", NULL};
	char *args4[] = {"env", "foo=foo4", "echo", "hello", NULL};
	char *args5[] = {"env", "echo", "hello", NULL};

	char *args20[] = {"env", "echo", "\"hello", NULL};

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	test_my_env(args1, 1);
	test_my_env(args2, 2);
	test_my_env(args1, 1);	// args2でセットした環境変数が消えていることを確認
	test_my_env(args3, 3);
	test_my_env(args4, 4);
	test_my_env(args5, 5);


	test_my_env(args20, 20);

}

#endif

#ifdef MY_UNSET_C

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"
#include "builtins/builtins.h"

extern t_env_list *g_env_list;

static void test_my_unset(char **args, int n)
{
	char *foo[] = {"export", "foo=foo", NULL};
	char *hoge[] = {"export", "hoge=hoge", NULL};
	char *ava[] = {"export", "ava=ava", NULL};
	char *simple_export[] = {"export", NULL};
	my_export(foo);
	my_export(hoge);
	my_export(ava);	

	ft_putnbr_fd(n, STD_OUT);
	ft_putendl_fd(" ==========", STD_OUT);
	my_unset(args);

	my_export(simple_export);
	pendl();
}

int main(int argc, char *argv[], char *envp[])
{
	char *args1[] = {"unset", "foo", NULL};
	char *args2[] = {"unset", "foo", "hoge", "ava", NULL};
	char *args3[] = {"unset", "hello", NULL};
	char *args4[] = {"unset", "num1", NULL};
	char *args5[] = {"unset", "_", NULL};
	char *args6[] = {"unset", "a_a", NULL};

	char *args10[] = {"unset", "foo=foo", NULL};
	char *args11[] = {"unset", "1foo", NULL};
	char *args12[] = {"unset", "a=a=a", NULL};
	char *args13[] = {"unset", "   foo", NULL};

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	test_my_unset(args1, 1);
	test_my_unset(args2, 2);
	test_my_unset(args3, 3);
	test_my_unset(args4, 4);
	test_my_unset(args5, 5);
	test_my_unset(args6, 6);


	test_my_unset(args10, 10);
	test_my_unset(args11, 11);
	test_my_unset(args12, 12);
	test_my_unset(args13, 13);
}

#endif

#ifdef MY_CD_C

#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"
#include "builtins/builtins.h"
#include "builtins/my_export.h"

extern t_env_list *g_env_list;

static void fix_pwd_env(char *save_oldpwd)
{
	t_env_list *pwd_node;
	t_env_list *old_pwd_node;

	pwd_node = search_env_node("PWD");
	old_pwd_node = search_env_node("OLDPWD");
	free(pwd_node->value);
	pwd_node->value = ft_strdup(old_pwd_node->value);
	free(old_pwd_node->value);
	old_pwd_node->value = ft_strdup(save_oldpwd);
}

static void test_my_cd(char **args, int n)
{
	char *save_oldpwd;
	char *pwd_str;
	char *old_pwd_str;

	errno = 0;
	ft_putnbr_fd(n, STD_OUT);
	ft_putendl_fd(" ==========", STD_OUT);
	save_oldpwd = ft_strdup(search_env_node("OLDPWD")->value);
	my_cd(args);
	pwd_str = create_env_str(search_env_node("PWD"));
	old_pwd_str = create_env_str(search_env_node("OLDPWD"));
	ft_putendl_fd(old_pwd_str, STD_OUT);
	ft_putendl_fd(pwd_str, STD_OUT);
	free(pwd_str);
	free(old_pwd_str);
	pendl();
	// my_cd実行前の状態に戻す
	if(n < 20)
	{
		chdir(search_env_node("OLDPWD")->value);
		fix_pwd_env(save_oldpwd);
	}
	free(save_oldpwd);
}

int main(int argc, char *argv[], char *envp[])
{
	char *args1[] = {"cd", "src", NULL};
	char *args2[] = {"cd", "..", NULL};
	char *args3[] = {"cd", NULL};
	char *args4[] = {"cd", "~", NULL};
	char *args5[] = {"cd", "/", NULL};
	char *args6[] = {"cd", ".", NULL};

	char *args20[] = {"cd", "Makefile", NULL};
	char *args21[] = {"cd", "test/test/test", NULL};	// Permission deniedのテスト
	char *args22[] = {"cd", "src", "study", NULL};

	char *args23[] = {"cd", "/root/", NULL};

	char *args24[] = {"cd", "/../../../../../../home", NULL};
	char *args25[] = {"cd", "/../../../../../../home/../home/../home", NULL};
	char *args26[] = {"cd", "~/.ssh", NULL};
	char *args27[] = {"cd", "~/../~/.ssh", NULL}; //error表示が異なる
	char *args28[] = {"cd", "~/notexist", NULL}; //error表示が異なる

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	test_my_cd(args1, 1);
	test_my_cd(args2, 2);
	test_my_cd(args3, 3);
	test_my_cd(args4, 4);
	test_my_cd(args5, 5);
	test_my_cd(args6, 6);


	// エラー
	test_my_cd(args20, 20);
	test_my_cd(args21, 21);
	test_my_cd(args22, 22);
	test_my_cd(args23, 23);

	//additional test
	test_my_cd(args24, 24);
	test_my_cd(args25, 25);
	test_my_cd(args26, 26);
	test_my_cd(args27, 27);
	test_my_cd(args28, 28);
}

#endif



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
	free_string_arr(allocated_arg);
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
#include <stddef.h>

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
