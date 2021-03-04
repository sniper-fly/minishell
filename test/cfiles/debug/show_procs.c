#include "debug.h"
#include "struct/process.h"
#include "constants.h"
#include "libft.h"

void	show_procs(t_process **procs)
{
	int		i;
	int		j;

	i = 0;
	while (procs[i])
	{
		j = 0;
		while (procs[i][j].is_end != TRUE)
		{
			show_string_arr(procs[i][j].cmd);
			ft_putstr_fd(", ", STD_OUT);
			j++;
		}
		ft_putchar_fd('\n', STD_OUT);
		i++;
	}
}
