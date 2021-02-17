#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "builtins/builtins.h"

static char **create_args_to_my_unset(char **args)
{
	int i;
	int key_count;
	char **keys;
	char *eq_ptr;

	i = 1;
	while(args[i] && ft_strchr(args[i], '='))
	{
		++i;
		++key_count;
	}
	keys = malloc(sizeof(char *) * (key_count + 2));	// TODO:エラー処理
	keys[0] = ft_strdup("unset");	// TODO:エラー処理
	i = 1;
	while(args[i] && (eq_ptr = ft_strchr(args[i], '=')))
	{
		keys[i] = ft_substr(args[i], 0, (size_t)(eq_ptr - args[i]));	// TODO:エラー処理
		++i;
	}
	keys[i] = NULL;
	return (keys);
}

void unset_tmp_env_vars(char **args)
{
	char **args_to_my_unset;

	args_to_my_unset = create_args_to_my_unset(args);
	my_unset(args_to_my_unset);
	free_string_arr(args_to_my_unset);
}