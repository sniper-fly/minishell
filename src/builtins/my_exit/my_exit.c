/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:36 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 16:25:30 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/t_bool.h"
#include "builtins/my_exit.h"
#include <signal.h>

extern volatile sig_atomic_t g_status;

static void		put_numeric_argument_error(char *arg)
{
	ft_putstr_fd("minishell: exit: ", STD_ERR);
	ft_putstr_fd(arg, STD_ERR);
	ft_putendl_fd(": numeric argument required", STD_ERR);
}

static t_bool	is_numeric_argument(char *arg)
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
	if (20 <= digit)
		return (FALSE);
	return (TRUE);
}

int				my_exit(char **args)
{
	int	i;

	ft_putendl_fd("exit", STD_ERR);
	i = 1;
	while (args[i])
	{
		if (1 < i)
		{
			ft_putendl_fd("minishell: exit: too many arguments", STD_ERR);
			g_status = GENERAL_ERRORS;
			return (GENERAL_ERRORS);
		}
		if (!is_numeric_argument(args[i]))
		{
			put_numeric_argument_error(args[i]);
			exit(MISUSE_OF_SHELL_BUILTINS);
		}
		++i;
	}
	if (!args[1])
		exit(g_status);
	if (args[1])
		exit(ft_atol(args[1]) & 255);
	return (SUCCEEDED);
}
