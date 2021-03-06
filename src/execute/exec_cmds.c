/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:12 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:13 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "utils.h"
#include "constants.h"
#include "execute.h"
#include "env_ctrl.h"
#include "exit_status.h"
#include "struct/process.h"
#include "builtins/builtins.h"
#include <signal.h>

extern volatile sig_atomic_t	g_status;

static void	wait_child_procs(pid_t last_pid, int count_procs)
{
	int		i;
	int		status;

	i = 0;
	waitpid(last_pid, &status, 0);
	if (WIFSIGNALED(status))
		g_status = WTERMSIG(status) + 128;
	else
		g_status = WEXITSTATUS(status);
	while (i < count_procs - 1)
	{
		wait(&status);
		if (WIFSIGNALED(status))
			g_status = WTERMSIG(status) + 128;
		++i;
	}
}

static void	exec_cmd(int i, int **pipe_fd, t_process *procs)
{
	char	**envp;

	close_and_dup_fds_in_child_proc(i, pipe_fd, procs);
	close_and_dup_fds_to_redirect(&(procs[i]));
	if (!(procs[i].cmd[0]))
		exit(SUCCEEDED);
	if (!(procs[i].cmd[0][0]))
		if_command_not_found(procs[i].cmd[0]);
	if (!ft_strcmp(procs[i].cmd[0], "exit"))
		my_exit_at_child_process(procs[i].cmd);
	if (is_builtin_func(procs[i].cmd[0]))
	{
		exec_builtins(procs[i].cmd);
		exit(g_status);
	}
	if (!(envp = get_env_array()))
		exit(malloc_error());
	my_execve(procs[i].cmd, envp);
}

void		exec_cmds(t_process *procs)
{
	int		i;
	int		**pipe_fd;
	pid_t	pid;

	i = 0;
	if (!(pipe_fd = create_pipe_fd_array(procs)))
	{
		g_status = malloc_error();
		return ;
	}
	while (procs[i].is_end != TRUE)
	{
		if (procs[i + 1].is_end != TRUE)
			pipe(pipe_fd[i]);
		if ((pid = fork()) == 0)
			exec_cmd(i, pipe_fd, procs);
		else if (i > 0)
		{
			close(pipe_fd[i - 1][0]);
			close(pipe_fd[i - 1][1]);
		}
		++i;
	}
	wait_child_procs(pid, count_procs(procs));
	free_pipe_fd_array(pipe_fd, procs);
}
