#include <stdlib.h>
#include "env_ctrl.h"
#include "exit_status.h"
#include "struct/env_list.h"
#include "builtins/my_export.h"

int	my_export(char **args)
{
	int			i;
	int			exit_status;
	t_env_list	**new_env_nodes;

	exit_status = SUCCEEDED;
	if (!args[1])
		print_env_at_my_export();
	else
	{
		new_env_nodes = create_new_env_nodes_arr(args, &exit_status);	// ここでエラーが起こるかも
		i = 0;
		while(new_env_nodes[i])
		{
			add_new_env_var_to_list(new_env_nodes[i]);
			++i;
		}
		// should free new_env_nodes
		free(new_env_nodes);
	}
	return (exit_status);
}