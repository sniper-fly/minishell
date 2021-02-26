#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"
#include "builtins/my_exit.h"

extern int g_status;

static long int	ft_abs(long int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

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

static int		get_exit_status(char **args)
{
	int			exit_status;
	long int	arg_status;

	if (!args[1])
		exit_status = g_status;
	else
	{
		arg_status = ft_atol(args[1]);
		if (arg_status < 0)
		{
			arg_status = ft_abs(arg_status);
			exit_status = arg_status % 256;
			exit_status = 256 - exit_status;
		}
		else
			exit_status = arg_status % 256;
	}
	return (exit_status);
}

int				my_exit(char **args)
{
	int	exit_status;

	ft_putendl_fd("exit", STD_ERR);
	if (2 < count_string_arr_row(args))
	{
		ft_putendl_fd("minishell: exit: too many arguments\n", STD_ERR);
		g_status = GENERAL_ERRORS;
		return (GENERAL_ERRORS);
	}
	if (20 <= count_digit(args[1]))
	{
		ft_putstr_fd("minishell: exit: ", STD_ERR);
		ft_putstr_fd(args[1], STD_ERR);
		ft_putendl_fd(": numeric argument required", STD_ERR);
		g_status = MISUSE_OF_SHELL_BUILTINS;
		exit(MISUSE_OF_SHELL_BUILTINS);
		return (MISUSE_OF_SHELL_BUILTINS);
	}
	exit_status = get_exit_status(args);
	g_status = exit_status;
	exit(exit_status);
	return (exit_status);
}
