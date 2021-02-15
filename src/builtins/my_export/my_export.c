#include "struct/env_list.h"
#include "builtins/my_export.h"

void	my_export(char **args)
{
	int			i;
	t_env_list	**new_env_nodes;

	if (!args[1])
		print_env();
	else
	{
		new_env_nodes = create_new_env_nodes_arr(args);
		i = 0;
		while(new_env_nodes[i])
		{
			add_new_env_var_to_list(new_env_nodes[i]);
			++i;
		}
		// should free new_env_nodes
	}
}