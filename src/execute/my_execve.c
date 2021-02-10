#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "libft.h"
#include "env_ctrl.h"
#include "my_execve.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/process.h"
#include "struct/env_list.h"

extern t_env_list	*g_env_list;

static int is_there_execute_file_at(char *cmd_path)
{
	int		fd;

	fd = open(cmd_path, O_WRONLY);
	return (fd != ERROR || errno != ENOENT);
}

static void check_if_the_full_path_is_valid(char *cmd_path)
{
	if (open(cmd_path, O_RDWR) == ERROR && (errno == EISDIR || errno == ENOENT))
	{
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_putstr_fd(cmd_path, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
		ft_putendl_fd(strerror(errno), STD_ERR);
		if(errno == EISDIR)
			exit(IS_DIR);
		else if(errno == ENOENT)
			exit(COMMAND_NOT_FOUND);
		else
			exit(FAILED);
	}
}

static void if_command_not_found(char *cmd_path)
{
	ft_putstr_fd(cmd_path, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd("command not found", STD_ERR);
	exit(COMMAND_NOT_FOUND);
}

static void do_execve(char *cmd_path, char **cmd, char **envp)
{
	// cmd[0] = cmd_path; // TODO:cmd[0]に代入必要?
	if (execve(cmd_path, cmd, envp) == ERROR)
	{
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_perror(cmd_path);
		if(errno == EACCES)
			exit(PERMISSION_DENIED);
		else
			exit(FAILED);	// TODO: exitのステータス要検証
	}
}

void		my_execve(char **cmd)
{
	int		i;
	char	*cmd_path;
	char	**envp;
	char	**path_db_ptr;

	envp = get_env_array();
	if(cmd[0][0] == '/')
		check_if_the_full_path_is_valid(cmd[0]);
	if (is_there_execute_file_at(cmd[0]))
		do_execve(cmd[0], cmd, envp);
	//1)envlstからPATHを取得し、PATHをsplitして二次元配列を作る。
	i = 0;
	path_db_ptr = get_path_array();	// TODO:free?
	while (path_db_ptr[i])
	{
		cmd_path = get_command_path(cmd[0], path_db_ptr[i]);
		//2)prefixをつけてファイルが存在するか（openできるか）検索
		//3)ファイルが見つかったらprefixをつけてarguments二次元ポインタに格納する
		if (is_there_execute_file_at(cmd_path))
			do_execve(cmd_path, cmd, envp);
		free(cmd_path);
		++i;
	}
	if_command_not_found(cmd[0]);
}
