#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"
#include "builtins/my_cd.h"
#include "builtins/builtins.h"

extern char			*g_pwd;
extern t_env_list	*g_env_list;

static int	set_env_pwd(char **args_for_my_export)
{
	char	*pwd;

	if (!(pwd = getcwd(NULL, 0)) && errno == ENOENT)
	{
		put_error_msg(NULL);
		if (!(pwd = ft_strjoin(g_pwd, "/.")))
			return (ERROR);
	}
	if (!(args_for_my_export[1] = ft_strjoin("PWD=", pwd)))
	{
		free_string_arr(args_for_my_export);
		return (ERROR);
	}
	free(pwd);
	return (SUCCESS);
}

static int	set_env_old_pwd(char **args_for_my_export)
{
	t_env_list	*pwd_node;

	if ((pwd_node = search_env_node("PWD")) != g_env_list)
	{
		if (!(args_for_my_export[2] = ft_strjoin("OLDPWD=", pwd_node->value)))
			return (ERROR);
	}
	else
		args_for_my_export[2] = NULL;
	return (SUCCESS);
}

int			change_env_vars(void)
{
	char		**args_for_my_export;

	if (!(args_for_my_export = malloc(sizeof(char *) * 4)))
		return (ERROR);
	if (!(args_for_my_export[0] = ft_strdup("export")))
	{
		free_string_arr(args_for_my_export);
		return (ERROR);
	}
	if (set_env_pwd(args_for_my_export) == ERROR
	|| set_env_old_pwd(args_for_my_export) == ERROR)
	{
		free_string_arr(args_for_my_export);
		return (ERROR);
	}
	args_for_my_export[3] = NULL;
	my_export(args_for_my_export);
	free_string_arr(args_for_my_export);
	return (SUCCESS);
}