#include "utils.h"
#include "debug.h"

void		show_tasks(char ***tasks)
{
	int		i;

	i = 0;
	while (tasks[i])
	{
		show_string_arr(tasks[i]);
		pendl();
		i++;
	}
}
