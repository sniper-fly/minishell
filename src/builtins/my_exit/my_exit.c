#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"
#include "builtins/my_exit.h"

extern int g_status;

static int		count_digit(char *status)
{
	int digit;

	digit = 0;
	if (*status == '-')
		++status;
	while (*status)
	{
		++digit;
		++status;
	}
	return (digit);
}

int				my_exit(char **args)
{
	ft_putendl_fd("exit", STD_ERR);
	if (args[1] && 20 <= count_digit(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STD_ERR);
		ft_putstr_fd(args[1], STD_ERR);
		ft_putendl_fd(": numeric argument required", STD_ERR);
		g_status = MISUSE_OF_SHELL_BUILTINS;
		exit(MISUSE_OF_SHELL_BUILTINS);
	}
	if (2 < count_string_arr_row(args))
	{
		ft_putendl_fd("minishell: exit: too many arguments\n", STD_ERR);
		g_status = GENERAL_ERRORS;
		return (GENERAL_ERRORS);
	}
	if (args[1])
		g_status = ft_atol(args[1]) & 255;
	exit(g_status);
}
