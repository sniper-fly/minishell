#include <stdlib.h>
#include "utils.h"
#include "execute.h"
#include "struct/process.h"

int		**create_pipe_fd_array(t_process *procs)
{
	int i;
	int num_of_procs;
	int **pipe_fd;

	i = 0;
	num_of_procs = count_procs(procs);
	if (!(pipe_fd = malloc(sizeof(int *) * num_of_procs)))
		exit(malloc_error());
	while (i < num_of_procs)
	{
		if (!(pipe_fd[i] = malloc(sizeof(int) * 2)))
			exit(malloc_error());
		++i;
	}
	return (pipe_fd);
}

void	free_pipe_fd_array(int **pipe_fd, t_process *procs)
{
	int i;
	int num_of_procs;

	i = 0;
	num_of_procs = count_procs(procs);
	while (i < num_of_procs)
	{
		free(pipe_fd[i]);
		++i;
	}
	free(pipe_fd);
}
