#include "utils.h"
#include "debug.h"

void		show_str_procs(char ***str_procs)
{
	int		i;

	i = 0;
	while (str_procs[i])
	{
		show_string_arr(str_procs[i]);
		pendl();
		i++;
	}
}
