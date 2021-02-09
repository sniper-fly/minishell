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