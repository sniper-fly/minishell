#include "libft.h"
#include "constants.h"
#include "struct/t_bool.h"
#include "builtins/my_env.h"

static t_bool is_there_no_cmds(char **args)
{
	int i;

	i = 1;
	while (args[i] && ft_strchr(args[i], '='))
		++i;
	if (!args[i])
		return (TRUE);
	return (FALSE);
}

void my_env(char **args)
{
	if (!args[1])
		print_env_at_my_env();
	else
	{
		export_tmp_env_vars(args);
		if(is_there_no_cmds(args))
			print_env_at_my_env();
		else
			exec_tasks_in_args(args);
		unset_tmp_env_vars(args);
	}
}