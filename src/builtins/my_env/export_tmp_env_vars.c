#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "builtins/builtins.h"

static int count_env_var_in_args(char **args)
{
	int i;
	int env_var_count;

	env_var_count = 0;
	i = 1;
	while (args[i] && ft_strchr(args[i], '='))
	{
		++env_var_count;
		++i;
	}
	return (env_var_count);
}

static char **create_args_to_my_export(char **args)
{
	int i;
	int env_var_count;
	char **args_to_my_export;

	if (!(env_var_count = count_env_var_in_args(args)))
		return NULL;
	args_to_my_export = malloc(sizeof(char *) * (env_var_count + 2));	// TODO:エラー処理
	i = 1;
	args_to_my_export[0] = ft_strdup("export");
	while (args[i] && ft_strchr(args[i], '='))
	{
		args_to_my_export[i] = ft_strdup(args[i]);
		++i;
	}
	args_to_my_export[i] = NULL;
	return (args_to_my_export);
}

void export_tmp_env_vars(char **args)
{
	char **args_to_my_export;

	if (!(args_to_my_export = create_args_to_my_export(args)))
		return ;
	my_export(args_to_my_export);
	free_string_arr(args_to_my_export);	//	?
}

