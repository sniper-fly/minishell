/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:03:59 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:00 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"

int		is_there_execute_file_at(char *cmd_path)
{
	int	fd;

	if ((fd = open(cmd_path, O_RDONLY)) == ERROR)
	{
		if (errno == EACCES)
		{
			ft_putstr_fd("minishell: ", STD_ERR);
			ft_perror(cmd_path);
			exit(COMMAND_CANNOT_EXECUTE);
		}
		return (FALSE);
	}
	close(fd);
	return (TRUE);
}

void	exit_if_command_path_is_dir(char *cmd_path)
{
	DIR	*dir;

	if ((dir = opendir(cmd_path)))
	{
		closedir(dir);
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_putstr_fd(cmd_path, STD_ERR);
		ft_putendl_fd(": Is a directory", STD_ERR);
		exit(COMMAND_CANNOT_EXECUTE);
	}
}

void	check_if_the_full_path_is_valid(char *cmd_path)
{
	int	fd;

	if ((fd = open(cmd_path, O_RDONLY)) == ERROR)
	{
		ft_putstr_fd("minishell: ", STD_ERR);
		ft_perror(cmd_path);
		if (errno == ENOENT || errno == EACCES)
			exit(COMMAND_NOT_FOUND);
		else
			exit(GENERAL_ERRORS);
	}
	close(fd);
}
