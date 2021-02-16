#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"
#include "builtins/my_export.h"

extern t_env_list *g_env_list;

static int count_env_node(void)
{
	int node_count;
	t_env_list *nil;
	t_env_list *env_node;

	node_count = 0;
	nil = g_env_list;
	env_node = g_env_list->next;
	while (env_node != nil)
	{
		if (ft_strcmp(env_node->key, "_"))	// _を表示しないため
			++node_count;
		env_node = env_node->next;
	}
	return (node_count);
}

static char **create_env_str_arr_from_env_list(int node_count)
{
	int i;
	char **env_str_arr;
	t_env_list *env_node;

	i = 0;
	env_node = g_env_list->next;
	env_str_arr = malloc(sizeof(char *)*(node_count+1));	// TODO:エラー処理
	while (i < node_count)
	{
		if (ft_strcmp(env_node->key, "_"))	// _を表示しないため
		{
			env_str_arr[i] = create_env_str(env_node);
			++i;
		}
		env_node = env_node->next;
	}
	env_str_arr[i] = NULL;
	return env_str_arr;
}

void	print_env(void)
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
}