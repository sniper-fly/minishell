#include <stdlib.h>
#include "libft.h"
#include "env_ctrl.h"
#include "struct/t_bool.h"
#include "struct/env_list.h"

static t_bool is_valid_env_key(char *key)
{
	if (!ft_strlen(key))
		return (FALSE);
	if ('0' <= *key && *key <= '9')
		return (FALSE);
	while (*key)
	{
		if(!ft_isalnum(*key) && *key != '_')
			return FALSE;
		++key;
	}
	return (TRUE);
}

static char *get_new_env_value(char *replica_of_arg)
{
	char *value;
	char *equal_ptr;

	if((equal_ptr = ft_strchr(replica_of_arg, '=')))
	{
		value = ft_strdup(equal_ptr + 1);	// TODO:エラー処理
	}
	else
		value = NULL;
	return (value);
}

static char *get_new_env_key(char *arg)
{
	char	*key;
	char	*equal_ptr;

	if((equal_ptr = ft_strchr(arg, '=')))
	{
		key = ft_substr(arg, 0, (size_t)(equal_ptr - arg));	// TODO:エラー処理
	}
	else
	{
		key = ft_strdup(arg);	// TODO:エラー処理
	}
	return (key);
}

t_env_list *make_new_env_node(char *arg)
{
	t_env_list	*new;

	new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	new->key = get_new_env_key(arg);
	new->value = get_new_env_value(arg);
	if(!is_valid_env_key(new->key))
	{
		free_env_node(new);
		return NULL;
	}
	return new;
}
