#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

/*
static void	set_ptr_at_doll_and_ptr_after_key
(char *value, char **ptr_at_doll, char **ptr_after_key)
{
	*ptr_at_doll = ft_strchr(value, '$');
	*ptr_after_key = *ptr_at_doll + 1;
	while (ft_isalpha(**ptr_after_key))
		++(*ptr_after_key);
}

static char *get_key_specified_in_dollar(char *value)
{
	char	*key_start_ptr;
	char	*ptr_after_key;
	char	*specific_key;

	set_ptr_at_doll_and_ptr_after_key(value, &key_start_ptr, &ptr_after_key);
	key_start_ptr += 1;	// $の次
	specific_key = ft_substr(value,	// エラー処理
	(unsigned int)(key_start_ptr - value),
	(size_t)(ptr_after_key - key_start_ptr));	// $で指定された環境変数のkeyを取得
	return (specific_key);
}

// 環境変数をその値で置換したvalueを返す
static char	*get_value_of_env_var_replaced
(char *old_value, t_env_list *specific_node)
{
	char	*ptr_at_doll;
	char	*ptr_after_key;
	char	*just_before_env_var;
	char	*value_with_env_var_catted;
	char	*new_value;

	set_ptr_at_doll_and_ptr_after_key(old_value, &ptr_at_doll, &ptr_after_key);
	*ptr_at_doll = '\0';
	just_before_env_var = ft_strdup(old_value);	// TODO:エラー処理
	if (specific_node == g_env_list)
		new_value = ft_strjoin(just_before_env_var, ptr_after_key);	// TODO:エラー処理
	else
	{
		value_with_env_var_catted =
		ft_strjoin(just_before_env_var, specific_node->value);	// TODO:エラー処理
		new_value = ft_strjoin(value_with_env_var_catted, ptr_after_key);	// TODO:エラー処理
		free(value_with_env_var_catted);
	}
	free(just_before_env_var);
	return (new_value);
}

static void	replace_env_var_with_its_value(t_env_list *env_node)
{
	char		*old_value;
	char		*new_value;
	char		*specific_key;
	t_env_list	*specific_node;

	new_value = env_node->value;
	while (ft_strchr(new_value, '$'))
	{
		old_value = new_value;
		specific_key = get_key_specified_in_dollar(old_value);
		specific_node = search_env_node(specific_key);	// segmentation fault?
		new_value =
		get_value_of_env_var_replaced(old_value, specific_node);
		free(old_value);
		free(specific_key);
	}
	env_node->value = new_value;
}
*/

t_env_list **create_new_env_nodes_arr(char **args, int *exit_status)
{
	int			i;
	t_env_list	**new_env_nodes;

	new_env_nodes =
	malloc(sizeof(t_env_list *) * (count_string_arr_row(args)));	// TODO:エラー処理
	i = 0;
	while (args[i + 1])
	{
		if(!(new_env_nodes[i] = make_new_env_node(args[i + 1])))
		{
			ft_putstr_fd("minishell: export: \'", STD_ERR);
			ft_putstr_fd(args[i + 1], STD_ERR);
			ft_putstr_fd("\': not a valid identifier\n", STD_ERR);
			*exit_status = GENERAL_ERRORS;
		}
		// if (new_env_nodes[i]->value && ft_strchr(new_env_nodes[i]->value, '$'))
		// 	replace_env_var_with_its_value(new_env_nodes[i]);	// $で指定された環境変数をその値と置換
		++i;
	}
	new_env_nodes[i] = NULL;
	return (new_env_nodes);
}
