#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "constants.h"
#include "struct/process.h"

int status;

static int count_procs(t_process *procs)
{
	int count;

	count = 0;
	while(procs[count].is_end != TRUE)
		++count;
	return count;
}

void wait_child_procs(pid_t last_pid, int count_procs)
{
	int i;

	i = 0;
	waitpid(last_pid, &status, 0);
	while(i <= count_procs){
		wait(NULL);
		++i;
	}
}

void close_and_dup_fds_in_child_proc(int i, int pipe_fd[][2], t_process *procs)
{

	if(i == 0)
	{
		dup2(pipe_fd[i][1], 1);
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
	}
	else if (procs[i+1].is_end == TRUE)
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

void exec_pipes(t_process *procs)
{
	int i;
	pid_t pid;
	int pipe_fd[count_procs(procs)][2];

	i = 0;
	while (procs[i].is_end != TRUE)
	{
		if (procs[i+1].is_end != TRUE)
			pipe(pipe_fd[i]);
		if ((pid = fork()) == 0)
		{
			close_and_dup_fds_in_child_proc(i, pipe_fd, procs);
			execvp(procs[i].cmd[0], procs[i].cmd);	// TODO: use my_execve
			exit(0);	// TODO: exitステータスの修正
		}
		else if (i > 0)
		{
			close(pipe_fd[i - 1][0]);
			close(pipe_fd[i - 1][1]);
			// TODO:リダイレクト処理
		}
		++i;
	}
	wait_child_procs(pid, count_procs(procs));
}

#ifdef EXEC_PIPES_C

#include "main.h"
#include "parse.h"
#include "debug.h"
#include "utils.h"
#include "read_cmd_line.h"

int main(void)
{
	int status;
	int pid;
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = parse_cmd_line(cmd_line, &status);
		if((pid = fork()))
			wait(&status);
		else
			exec_pipes(cmd_procs[0]);
	}
}

#endif