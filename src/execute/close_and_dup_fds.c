/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_dup_fds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:05 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:05 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "unistd.h"
#include "constants.h"
#include "struct/process.h"

void	close_and_dup_fds_in_child_proc(int i, int **pipe_fd, t_process *procs)
{
	if (i == 0)
	{
		if (procs[1].is_end == TRUE)
			return ;
		dup2(pipe_fd[i][1], 1);
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
	}
	else if (procs[i + 1].is_end == TRUE)
	{
		dup2(pipe_fd[i - 1][0], 0);
		close(pipe_fd[i - 1][0]);
		close(pipe_fd[i - 1][1]);
	}
	else
	{
		dup2(pipe_fd[i - 1][0], 0);
		dup2(pipe_fd[i][1], 1);
		close(pipe_fd[i - 1][0]);
		close(pipe_fd[i - 1][1]);
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
	}
}

void	close_and_dup_fds_to_redirect(t_process *proc)
{
	int	fd;

	if (proc->red_in_file_name)
	{
		fd = open(proc->red_in_file_name, O_RDONLY);
		close(0);
		dup2(fd, 0);
		close(fd);
	}
	if (proc->red_out_file_name)
	{
		fd = open(proc->red_out_file_name, proc->red_out_mode);
		close(1);
		dup2(fd, 1);
		close(fd);
	}
	if (proc->red_err_file_name)
	{
		fd = open(proc->red_err_file_name, proc->red_err_mode);
		close(2);
		dup2(fd, 2);
		close(fd);
	}
}
