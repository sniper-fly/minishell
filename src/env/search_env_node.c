#include "env_ctrl.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

t_env_list	*search_env_node(char *search_key)
{
	t_env_list	*nil;
	t_env_list	*env_node;

	nil = g_env_list;
	env_node = g_env_list->next;
	while (env_node != nil)
	{
		if (!ft_strcmp(env_node->key, search_key))
			return (env_node);
		env_node = env_node->next;
	}
	return (nil);
}