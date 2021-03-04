/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tasks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:15 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:16 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "parse.h"
#include "utils.h"
#include "execute.h"
#include "exit_status.h"
#include "struct/t_bool.h"
#include "struct/process.h"
#include "builtins/builtins.h"
#include <signal.h>

extern volatile sig_atomic_t	g_status;

static t_bool	should_exec_builtin_func(t_process *procs)
{
	if (procs[1].is_end != TRUE)
		return (FALSE);
	if (!(procs[0].cmd[0]))
		return (FALSE);
	if (is_builtin_func(procs[0].cmd[0]))
		return (TRUE);
	return (FALSE);
}

static void		reset_standard_fds(
	t_process *proc, int fd_stdin, int fd_stdout, int fd_stderr)
{
	int	fd;

	fd = 255;
	if (proc->red_in_file_name)
	{
		dup2(0, fd);
		close(fd);
		dup2(fd_stdin, 0);
	}
	if (proc->red_out_file_name)
	{
		dup2(1, fd);
		close(fd);
		dup2(fd_stdout, 1);
	}
	if (proc->red_err_file_name)
	{
		dup2(2, fd);
		close(fd);
		dup2(fd_stderr, 2);
	}
}

static void		exec_single_process_builtin(t_process *proc)
{
	int	fd_stdin;
	int	fd_stdout;
	int	fd_stderr;

	fd_stdin = dup(0);
	fd_stdout = dup(1);
	fd_stderr = dup(2);
	close_and_dup_fds_to_redirect(proc);
	exec_builtins(proc->cmd);
	reset_standard_fds(proc, fd_stdin, fd_stdout, fd_stderr);
}

void			exec_tasks(char ***tasks)
{
	int			i;
	t_process	*procs;

	i = 0;
	while (tasks[i])
	{
		procs = parse_each_task(tasks[i]);
		if (should_exec_builtin_func(procs))
			exec_single_process_builtin(&procs[0]);
		else
			exec_cmds(procs);
		free_procs(procs);
		++i;
	}
}
