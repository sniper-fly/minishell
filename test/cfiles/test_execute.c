#ifdef TEST_REDIRECT

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "parse.h"
#include "execute.h"
#include "env_ctrl.h"

static void test_redirect(char *cmd_line, int n)
{
	char ***tasks;

	ft_putnbr_fd(n, 1);
	ft_putendl_fd(" ====================", 1);
	tasks = convert_line2tasks(cmd_line);
	exec_tasks(tasks);
	free_tasks(tasks);
	pendl();
}

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	create_env_list(envp);

	char *cmd_lines[] =
	{
		"ls",
		"wc < Makefile",
		"ls > ./test/var_parse/execute1",
		"wc < Makefile > ./test/var_parse/execute2",
		"wc < unit_test.sh < Makefile > ./test/var_parse/execute3",
		"wc < Makefile > ./test/var_parse/execute4 > ./test/var_parse/execute5",
		"wc < unit_test.sh < Makefile > ./test/var_parse/execute6 > ./test/var_parse/execute7",
		"wc < Makefile >> ./test/var_parse/execute8",
		"wc < Makefile >> ./test/var_parse/execute8"
	};
	for(size_t i = 0; i < sizeof(cmd_lines)/sizeof(char *); ++i)
		test_redirect(cmd_lines[i], i);
}

#endif

#ifdef EXEC_CMD_C

#include <sys/wait.h>
#include "execute.h"
#include "main.h"
#include "parse.h"
#include "utils.h"
#include "debug.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"
#include <signal.h>

extern volatile sig_atomic_t g_status;

int main(void)
{
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = generate_simple_procs(cmd_line);
		exec_cmd_for_debug(cmd_procs);
		ft_putnbr_fd(WEXITSTATUS(g_status), 1);
		pendl();
	}
}

#endif

#ifdef EXEC_PIPES_C

#include <sys/wait.h>
#include "main.h"
#include "parse.h"
#include "debug.h"
#include "utils.h"
#include "libft.h"
#include "execute.h"
#include "env_ctrl.h"
#include "constants.h"
#include "read_cmd_line.h"
#include <signal.h>

extern volatile sig_atomic_t g_status;

int main(int argc, char *argv[], char *envp[])
{
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);
	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = generate_simple_procs(cmd_line);
		exec_pipes(cmd_procs[0]);
		ft_putnbr_fd(WEXITSTATUS(g_status), 1);
		pendl();
	}
}

#endif

#ifdef MY_EXECVE_C

#include <stdlib.h>
#include <unistd.h>
#include "execute.h"
#include "env_ctrl.h"
#include <sys/wait.h>

static void exec_test(char **cmd, char **envp)
{
	if(fork())
		wait(NULL);
	else{
		my_execve(cmd, envp);
		exit(0);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char *cmd[] = {"ls", NULL};
	
	char *cmd1[] = {"/bin/ls", NULL};
	// ディレクトリを指定

	char *cmd2[] = {"/bin/", NULL};
	// ディレクトリを指定

	char *cmd3[] = {"/root/a", NULL};
	// 実行権限がないファイル

	char *cmd4[] = {"/not/exist", NULL};
	//存在しないファイル

	char *cmd5[] = {"notexist", NULL};
	//存在しないファイル
	argc += 0;
	argv[0][0] = 'A';
	create_env_list(envp);
	exec_test(cmd, envp);
	exec_test(cmd1, envp);
	exec_test(cmd2, envp);
	exec_test(cmd3, envp);
	exec_test(cmd4, envp);
	exec_test(cmd5, envp);
}

#endif

#ifdef 	CHECK_EXIT_STATUS_OF_MY_EXECVE_C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "execute.h"
#include "env_ctrl.h"
#include <sys/wait.h>
#include "libft.h"
#include "constants.h"
#include "utils.h"

static void exec_test_and_output_exit_status(char **cmd, char **envp)
{
	int status;

	ft_putstr_fd("=====================\n", STD_OUT);
	if(fork()){
		wait(&status);
		ft_putstr_fd("status:", STD_OUT);
		ft_putnbr_fd(WEXITSTATUS(status), STD_OUT);
		pendl();
	}else{
		my_execve(cmd, envp);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char *cmd[] = {"ls", NULL};
	
	char *cmd1[] = {"/bin/ls", NULL};
	// ディレクトリを指定

	char *cmd2[] = {"/bin/", NULL};
	// ディレクトリを指定

	char *cmd3[] = {"/root/a", NULL};
	// 実行権限がないファイル

	char *cmd4[] = {"/not/exist", NULL};
	//存在しないファイル

	char *cmd5[] = {"notexist", NULL};
	//存在しないファイル
	argc += 0;
	argv[0][0] = 'A';
	create_env_list(envp);
	exec_test_and_output_exit_status(cmd, envp);
	exec_test_and_output_exit_status(cmd1, envp);
	exec_test_and_output_exit_status(cmd2, envp);
	exec_test_and_output_exit_status(cmd3, envp);
	exec_test_and_output_exit_status(cmd4, envp);
	exec_test_and_output_exit_status(cmd5, envp);
}

#endif