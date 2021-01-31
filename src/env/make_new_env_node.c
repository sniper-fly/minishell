#include <stdlib.h>
#include "libft.h"
#include "struct/env_list.h"

t_env_list *make_new_env_node(char *envp_i)
{
	t_env_list *new;
	char **splitted;

	new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	splitted = ft_split(envp_i, '=');	// TODO:エラー処理
	new->key = splitted[0];
	new->value = splitted[1];
	free(splitted);
	return new;
}

#ifdef 	MAKE_NEW_ENV_NODE_C

#include <stdio.h>

int main(void)
{
	t_env_list *new;
	char *test_env = "foo=foo";

	new = make_new_env_node(test_env);
	printf("key:%s\n", new->key);
	printf("value:%s\n", new->value);
	free(new->key);
	free(new->value);
	free(new);
}

#endif