#include <stdlib.h>
#include "struct/env_list.h"

void	free_env_node(t_env_list *env_node)
{
	free(env_node->key);
	free(env_node->value);
	free(env_node);
}
