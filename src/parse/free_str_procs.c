#include "utils.h"	
#include <stdlib.h>

void		free_str_procs(char ***str_procs)
{
	int		i;

	i = 0;
	while (str_procs[i])
	{
		free_string_arr(str_procs[i]);
		i++;
	}
	free(str_procs);
}
