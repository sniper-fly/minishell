#include "utils.h"	
#include <stdlib.h>

void		free_tasks(char ***tasks)
{
	int		i;

	i = 0;
	while (tasks[i])
	{
		free_string_arr(tasks[i]);
		i++;
	}
	free(tasks);
}
