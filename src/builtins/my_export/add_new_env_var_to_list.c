/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_env_var_to_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:42 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:51:43 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_ctrl.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

void	add_new_env_var_to_list(t_env_list *new_env_node)
{
	t_env_list	*old_env_node;

	if ((old_env_node = search_env_node(new_env_node->key)) == g_env_list)
	{
		new_env_node->next = g_env_list;
		g_env_list->prev->next = new_env_node;
		new_env_node->prev = g_env_list->prev;
		g_env_list->prev = new_env_node;
	}
	else
	{
		if (new_env_node->value)
		{
			new_env_node->prev = old_env_node->prev;
			old_env_node->prev->next = new_env_node;
			new_env_node->next = old_env_node->next;
			new_env_node->next->prev = new_env_node;
			free_env_node(old_env_node);
		}
		else
			free_env_node(new_env_node);
	}
}
