#include <stdlib.h>
#include "libft.h"
#include "struct/env_list.h"

t_env_list *make_new_env_node(char *raw_env_var)
{
	t_env_list *new;
	char *equal_ptr;
	char *key_ptr;
	char *val_ptr;

	new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	key_ptr = raw_env_var;
	equal_ptr = ft_strchr(raw_env_var, '=');	// TODO:エラー処理
	*equal_ptr = '\0';
	val_ptr = equal_ptr + 1;
	new->key = ft_strdup(key_ptr);	// TODO?エラー処理
	new->value = ft_strdup(val_ptr);	// TODO:エラー処理
	return new;
}

#ifdef 	MAKE_NEW_ENV_NODE_C

#include <stdio.h>

int main(void)
{
	t_env_list *new;
	char test_env[] = "foo=foo";

	new = make_new_env_node(test_env);
	printf("key:%s\n", new->key);
	printf("value:%s\n", new->value);
	free(new->key);
	free(new->value);
	free(new);
}

#endif