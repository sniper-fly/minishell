#include <stdlib.h>
#include "libft.h"
#include "struct/env_list.h"

t_env_list *make_new_env_node(char *raw_env_var)
{
	char		*equal_ptr;
	char		*key_ptr;
	char		*val_ptr;
	t_env_list	*new;

	new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	key_ptr = raw_env_var;
	equal_ptr = ft_strchr(raw_env_var, '=');	// TODO:エラー処理
	if(equal_ptr)
	{
		*equal_ptr = '\0';
		val_ptr = equal_ptr + 1;
		new->value = ft_strdup(val_ptr);	// TODO:エラー処理
	}
	else
		new->value = NULL;
	new->key = ft_strdup(key_ptr);	// TODO?エラー処理
	return new;
}
