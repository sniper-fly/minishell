#include "libft.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

void my_unset(char **args)
{
	int i;
	t_env_list *delete_node;

	i = 1;
	while (args[i])
	{
		if (!is_valid_env_key(args[i]))
		{
			ft_putstr_fd("minishell: unset: \'", STD_ERR);
			ft_putstr_fd(args[i], STD_ERR);
			ft_putstr_fd("\': not a valid identifier\n", STD_ERR);
			++i;
			continue;
		}
		if ((delete_node = search_env_node(args[i])) == g_env_list)
		{
			++i;
			continue;
		}
		delete_node->prev->next = delete_node->next;
		delete_node->next->prev = delete_node->prev;
		free_env_node(delete_node);
		++i;
	}
}