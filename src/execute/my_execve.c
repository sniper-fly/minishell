#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "libft.h"
#include "execute.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/process.h"
#include "struct/env_list.h"
#include <signal.h>

extern volatile sig_atomic_t g_status;
extern t_env_list	*g_env_list;

static int	is_there_execute_file_at(char *cmd_path)
{
	int	fd;

	fd = open(cmd_path, O_WRONLY);
	return (fd != ERROR || errno != ENOENT);
}

static void	check_if_the_full_path_is_valid(char *cmd_path)
{
	if (open(cmd_path, O_RDWR) == ERROR && (errno == EISDIR || errno == ENOENT))
	{
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_putstr_fd(cmd_path, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
		ft_putendl_fd(strerror(errno), STD_ERR);
		if (errno == EISDIR)
			exit(COMMAND_CANNOT_EXECUTE);
		else if (errno == ENOENT)
			exit(COMMAND_NOT_FOUND);
		else
			exit(GENERAL_ERRORS);
	}
}

static void	do_execve(char *cmd_path, char **cmd, char **envp)
{
	if (execve(cmd_path, cmd, envp) == ERROR)
	{
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_perror(cmd_path);
		if (errno == EACCES)
			exit(COMMAND_CANNOT_EXECUTE);
		else
			exit(GENERAL_ERRORS);	// TODO: exitのステータス要検証
	}
}

static char	*get_command_path(char *cmd)
{
	int		i;
	char	*cmd_path;
	char	**path_db_ptr;

	if (!(path_db_ptr = get_path_array()))
	{
		g_status = malloc_error();
		return (NULL);
	}
	i = 0;
	while (path_db_ptr[i])
	{
		if (!(cmd_path = join_cmd_to_path(cmd, path_db_ptr[i])))
		{
			g_status = malloc_error();
			return (NULL);
		}
		if (is_there_execute_file_at(cmd_path))
			return (cmd_path);
		free(cmd_path);
		++i;
	}
	free_string_arr(path_db_ptr);
	return (NULL);
}

void		my_execve(char **cmd, char **envp)
{
	char *cmd_path;

	if (cmd[0][0] == '/')
		check_if_the_full_path_is_valid(cmd[0]);
	if (is_there_execute_file_at(cmd[0]))
		do_execve(cmd[0], cmd, envp);
	if ((cmd_path = get_command_path(cmd[0])))
		do_execve(cmd_path, cmd, envp);
	else if (g_status != GENERAL_ERRORS)
		if_command_not_found(cmd[0]);
}
