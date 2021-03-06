/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:13 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:52:14 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

static void	print_env_at_my_env(void)
{
	t_env_list *nil;
	t_env_list *env_node;

	nil = g_env_list;
	env_node = g_env_list->next;
	while (env_node != nil)
	{
		if (env_node->value)
		{
			ft_putstr_fd(env_node->key, STD_OUT);
			ft_putstr_fd("=", STD_OUT);
			ft_putendl_fd(env_node->value, STD_OUT);
		}
		env_node = env_node->next;
	}
}

int			my_env(char **args)
{
	if (!ft_strcmp(args[0], "env"))
		print_env_at_my_env();
	return (SUCCEEDED);
}
