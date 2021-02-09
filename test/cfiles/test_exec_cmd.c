#include "exec_cmd.h"

#ifdef EXEC_CMD_C

#include "main.h"
#include "parse.h"
#include "utils.h"
#include "debug.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"

int main(void)
{
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = parse_cmd_line(cmd_line, &g_status);
		exec_cmd(cmd_procs);
		ft_putnbr_fd(WEXITSTATUS(g_status), 1);
		pendl();
	}
}

#endif

#ifdef EXEC_PIPES_C

#include "main.h"
#include "parse.h"
#include "debug.h"
#include "utils.h"
#include "libft.h"
#include "env_ctrl.h"
#include "read_cmd_line.h"

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
		cmd_procs = parse_cmd_line(cmd_line, &g_status);
		exec_pipes(cmd_procs[0]);
		ft_putnbr_fd(WEXITSTATUS(g_status), 1);
		pendl();
	}
}

#endif

#ifdef MY_EXECVE_C

#include <sys/wait.h>

static void exec_test(char **cmd)
{
	if(fork())
		wait(NULL);
	else{
		my_execve(cmd);
		exit(0);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char *cmd[] = {"ls", "-l", NULL};
	
	char *cmd1[] = {"/bin/ls", "-l", NULL};
	// ディレクトリを指定

	char *cmd2[] = {"/bin/", "-l", NULL};
	// ディレクトリを指定

	char *cmd3[] = {"/root/a", "-l", NULL};
	// 実行権限がないファイル

	char *cmd4[] = {"/not/exist", "-l", NULL};
	//存在しないファイル

	char *cmd5[] = {"notexist", "-l", NULL};
	//存在しないファイル
	argc += 0;
	argv[0][0] = 'A';
	create_env_list(envp);
	exec_test(cmd);
	exec_test(cmd1);
	exec_test(cmd2);
	exec_test(cmd3);
	exec_test(cmd4);
	exec_test(cmd5);
}

#endif