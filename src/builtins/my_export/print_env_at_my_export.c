/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env_at_my_export.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:57 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:51:58 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/env_list.h"
#include "builtins/my_export.h"

extern t_env_list *g_env_list;

static int	count_env_node(void)
{
	int			node_count;
	t_env_list	*nil;
	t_env_list	*env_node;

	node_count = 0;
	nil = g_env_list;
	env_node = g_env_list->next;
	while (env_node != nil)
	{
		if (ft_strcmp(env_node->key, "_"))
			++node_count;
		env_node = env_node->next;
	}
	return (node_count);
}

static char	**create_env_str_arr_from_env_list(int node_count)
{
	int			i;
	char		**env_str_arr;
	t_env_list	*env_node;

	i = 0;
	env_node = g_env_list->next;
	if (!(env_str_arr = malloc(sizeof(char *) * (node_count + 1))))
		exit(malloc_error());
	while (i < node_count)
	{
		if (ft_strcmp(env_node->key, "_"))
		{
			env_str_arr[i] = create_env_str(env_node);
			++i;
		}
		env_node = env_node->next;
	}
	env_str_arr[i] = NULL;
	return (env_str_arr);
}

int			print_env_at_my_export(void)
{
	int		i;
	char	**env_str_arr;

	env_str_arr = create_env_str_arr_from_env_list(count_env_node());
	sort_keys_by_lexical_order(env_str_arr);
	i = 0;
	while (env_str_arr[i])
	{
		ft_putstr_fd("declare -x ", STD_OUT);
		ft_putendl_fd(env_str_arr[i], STD_OUT);
		++i;
	}
	free_string_arr(env_str_arr);
	return (SUCCEEDED);
}
