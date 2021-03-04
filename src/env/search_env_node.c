/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:57:57 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:57:58 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "env_ctrl.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

t_env_list	*search_env_node(char *search_key)
{
	t_env_list	*nil;
	t_env_list	*env_node;

	nil = g_env_list;
	env_node = g_env_list->next;
	while (env_node != nil)
	{
		if (!ft_strcmp(env_node->key, search_key))
			return (env_node);
		env_node = env_node->next;
	}
	return (nil);
}
