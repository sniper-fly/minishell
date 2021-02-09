#include "env_ctrl.h"
#include "struct/env_list.h"

#ifdef CREATE_ENV_LIST_C

int	main(int argc, char *argv[], char *envp[])
{
	t_env_list *env_node;

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);
	env_node = g_env_list->next;
	while(env_node != g_env_list)
	{
		printf("%s=%s\n", env_node->key, env_node->value);
		env_node = env_node->next;
	}
}

#endif


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