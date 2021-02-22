#include "libft.h"
#include "constants.h"
#include "exit_status.h"

static void	set_idx_and_endline_flag(char **args, int *idx, int *endline_flag)
{
	int	j;

	*idx = 1;
	while (args[*idx])
	{
		if (args[*idx][0] != '-')
			return ;
		j = 1;
		while (args[*idx][j])
		{
			if (args[*idx][j] != 'n')
				return ;
			++j;
		}
		*endline_flag = 0;
		++(*idx);
	}
}

int			my_echo(char **args)
{
	int	idx;
	int	endline_flag;

	endline_flag = 1;
	if (args[1] != NULL)
	{
		set_idx_and_endline_flag(args, &idx, &endline_flag);
		while (args[idx])
		{
			ft_putstr_fd(args[idx], STD_OUT);
			if (args[idx + 1])
				ft_putchar_fd(' ', STD_OUT);
			++idx;
		}
	}
	if (endline_flag)
		ft_putstr_fd("\n", STD_OUT);
	return (SUCCEEDED);
}
