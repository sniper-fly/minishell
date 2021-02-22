#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

t_env_list	**create_new_env_nodes_arr(char **args, int *exit_status)
{
	int			i;
	t_env_list	**new_env_nodes;

	if (!(new_env_nodes =
	malloc(sizeof(t_env_list *) * (count_string_arr_row(args)))))
		return (NULL);
	i = 0;
	while (args[i + 1])
	{
		if (!(new_env_nodes[i] = make_new_env_node(args[i + 1])))
		{
			ft_putstr_fd("minishell: export: \'", STD_ERR);
			ft_putstr_fd(args[i + 1], STD_ERR);
			ft_putstr_fd("\': not a valid identifier\n", STD_ERR);
			*exit_status = GENERAL_ERRORS;
		}
		++i;
	}
	new_env_nodes[i] = NULL;
	return (new_env_nodes);
}
