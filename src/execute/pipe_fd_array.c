#include <stdlib.h>
#include "execute.h"
#include "struct/process.h"

int **create_pipe_fd_array(t_process *procs)
{
	int i;
	int num_of_procs;
	int **pipe_fd;

	i = 0;
	num_of_procs = count_procs(procs);
	pipe_fd = malloc(sizeof(int *)*num_of_procs);	// TODO:mallocエラー処理
	while(i < num_of_procs)
	{
		pipe_fd[i] = malloc(sizeof(int)*2); // TODO:mallocエラー処理
		++i;
	}
	return pipe_fd;
}

void free_pipe_fd_array(int **pipe_fd, t_process *procs)
{
	int i;
	int num_of_procs;

	i = 0;
	num_of_procs = count_procs(procs);
	while(i < num_of_procs)
	{
		free(pipe_fd[i]);
		++i;
	}
	free(pipe_fd);
}
