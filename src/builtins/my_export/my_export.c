#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
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
		exit_status = print_env_at_my_export();
	else
	{
		new_env_nodes = create_new_env_nodes_arr(args, &exit_status);
		i = 0;
		while (new_env_nodes[i])
		{
			add_new_env_var_to_list(new_env_nodes[i]);
			++i;
		}
		free(new_env_nodes);
	}
	return (exit_status);
}
