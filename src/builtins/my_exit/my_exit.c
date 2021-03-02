#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/t_bool.h"
#include "builtins/my_exit.h"
#include <signal.h>

extern volatile sig_atomic_t g_status;

static int		is_numeric_argument(char *arg)
{
	int	i;
	int digit;

	i = 0;
	digit = 0;
	if (arg[i] == '-' || arg[i] == '+')
		++i;
	while (arg[i])
	{
		if (arg[i] < '0' || '9' < arg[i])
			return (FALSE);
		++digit;
		++i;
	}
	if (20 < digit)
		return (FALSE);
	return (TRUE);
}

int				my_exit(char **args)
{
	int	i;

	ft_putendl_fd("exit", STD_ERR);
	i = 1;
	while(args[i])
	{
		if (1 < i)
		{
			ft_putendl_fd("minishell: exit: too many arguments", STD_ERR);
			g_status = GENERAL_ERRORS;
			return (GENERAL_ERRORS);
		}
		if (!is_numeric_argument(args[i]))
		{
			ft_putstr_fd("minishell: exit: ", STD_ERR);
			ft_putstr_fd(args[i], STD_ERR);
			ft_putendl_fd(": numeric argument required", STD_ERR);
			g_status = MISUSE_OF_SHELL_BUILTINS;
			exit(MISUSE_OF_SHELL_BUILTINS);
		}
		++i;
	}
	if (args[1])
		g_status = ft_atol(args[1]) & 255;
	exit(g_status);
}
