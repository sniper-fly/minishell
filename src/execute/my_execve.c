/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:33 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:34 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <dirent.h>
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

static void	do_execve(char *cmd_path, char **cmd, char **envp)
{
	if (execve(cmd_path, cmd, envp) == ERROR)
	{
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_perror(cmd_path);
		if (errno == EACCES)
			exit(COMMAND_CANNOT_EXECUTE);
		else
			exit(GENERAL_ERRORS);
	}
}

static char	*get_command_path(char *cmd)
{
	int		i;
	char	*cmd_path;
	char	**path_db_ptr;

	if (!(path_db_ptr = get_path_array()))
		return (NULL);
	i = 0;
	while (path_db_ptr[i])
	{
		cmd_path = join_cmd_to_path(cmd, path_db_ptr[i]);
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

	exit_if_command_path_is_dir(cmd[0]);
	if (cmd[0][0] == '/')
		check_if_the_full_path_is_valid(cmd[0]);
	if (is_there_execute_file_at(cmd[0]))
		do_execve(cmd[0], cmd, envp);
	if ((cmd_path = get_command_path(cmd[0])))
		do_execve(cmd_path, cmd, envp);
	else
		if_command_not_found(cmd[0]);
}
