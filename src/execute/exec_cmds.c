#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "utils.h"
#include "constants.h"
#include "execute.h"
#include "my_execve.h"
#include "exit_status.h"
#include "struct/process.h"
#include "builtins/builtins.h"

extern int	g_status;

static void	wait_child_procs(pid_t last_pid, int count_procs)
{
	int i;

	i = 0;
	waitpid(last_pid, &g_status, 0);
	while(i < count_procs - 1){
		wait(NULL);
		++i;
	}
}

static void exec_cmd(t_process proc)
{
	close_and_dup_fds_to_redirect(proc);
	if (is_builtin_func(proc.cmd[0]))
	{
		exec_builtins(proc.cmd);
		exit(g_status);
	}
	my_execve(proc.cmd);
}

void		exec_cmds(t_process *procs)
{
	int i;
	pid_t pid;
	int **pipe_fd;

	i = 0;
	pipe_fd = create_pipe_fd_array(procs);
	while (procs[i].is_end != TRUE)
	{
		if (procs[i+1].is_end != TRUE)
			pipe(pipe_fd[i]);
		if ((pid = fork()) == 0)
		{
			if (procs[i + 1].is_end != TRUE)
				close_and_dup_fds_in_child_proc(i, pipe_fd, procs);
			exec_cmd(procs[i]);
		}
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
