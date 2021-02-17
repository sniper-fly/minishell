#include "libft.h"
#include "constants.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

void print_env_at_my_env(void)
{
	t_env_list *nil;
	t_env_list *env_node;

	nil = g_env_list;
	env_node = g_env_list->next;
	while(env_node != nil)
	{
		ft_putstr_fd(env_node->key, STD_OUT);
		ft_putstr_fd("=", STD_OUT);
		ft_putendl_fd(env_node->value, STD_OUT);
		env_node = env_node->next;
	}
}

