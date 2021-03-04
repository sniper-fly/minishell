/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:21 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:52:21 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

static void	put_invalid_env_key_error(char *key)
{
	ft_putstr_fd("minishell: unset: \'", STD_ERR);
	ft_putstr_fd(key, STD_ERR);
	ft_putstr_fd("\': not a valid identifier\n", STD_ERR);
}

static void	unset_env_node(t_env_list *delete_node)
{
	delete_node->prev->next = delete_node->next;
	delete_node->next->prev = delete_node->prev;
	free_env_node(delete_node);
}

int			my_unset(char **args)
{
	int			i;
	int			exit_status;
	t_env_list	*delete_node;

	i = 1;
	exit_status = SUCCEEDED;
	while (args[i])
	{
		if (!is_valid_env_key(args[i]))
		{
			put_invalid_env_key_error(args[i]);
			++i;
			exit_status = GENERAL_ERRORS;
			continue;
		}
		if ((delete_node = search_env_node(args[i])) == g_env_list)
		{
			++i;
			continue;
		}
		unset_env_node(delete_node);
		++i;
	}
	return (exit_status);
}
