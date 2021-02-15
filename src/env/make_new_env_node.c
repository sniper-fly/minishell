#include <stdlib.h>
#include "libft.h"
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

t_env_list *make_new_env_node(char *arg)
{
	char *raw_env_var;
	char		*equal_ptr;
	char		*key_ptr;
	char		*val_ptr;
	t_env_list	*new;

	raw_env_var = ft_strdup(arg);	// TODO:malloc
	new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	key_ptr = raw_env_var;
	if((equal_ptr = ft_strchr(raw_env_var, '=')))
	{
		*equal_ptr = '\0';
		val_ptr = equal_ptr + 1;
		new->value = ft_strdup(val_ptr);	// TODO:エラー処理
	}
	else
		new->value = NULL;
	if(!is_valid_env_key(key_ptr))
		return NULL;
	new->key = ft_strdup(key_ptr);	// TODO?エラー処理
	free(raw_env_var);
	return new;
}
