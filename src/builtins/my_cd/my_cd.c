#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "builtins/my_cd.h"
#include "builtins/builtins.h"

extern char			*g_pwd;
extern t_env_list	*g_env_list;

static char		*replace_homedir_with_path(char *arg)
{
	char	*path;
	char	*homedir_path;

	homedir_path = search_env_node("HOME")->value;
	if (!arg)
	{
		if (!(path = ft_strdup(homedir_path)))
			return (NULL);
	}
	else
	{
		if (!(path = ft_strjoin(homedir_path, &arg[1])))
			return (NULL);
	}
	return (path);
}

static char		*set_path(char *arg)
{
	char	*path;

	if (!arg || arg[0] == '~')
	{
		if (!(path = replace_homedir_with_path(arg)))
			return (NULL);
	}
	else
	{
		if (!(path = ft_strdup(arg)))
			return (NULL);
	}
	return (path);
}

static t_bool	is_valid_arg(char **args)
{
	if (2 < count_string_arr_row(args))
	{
		ft_putendl_fd("minishell: cd: too many arguments", STD_ERR);
		return (FALSE);
	}
	if (!args[1] && search_env_node("HOME") == g_env_list)
	{
		ft_putendl_fd("minishell: cd: HOME not set", STD_ERR);
		return (FALSE);
	}
	return (TRUE);
}

int				my_cd(char **args)
{
	char	*path;
	char	*new_pwd;

	if (!is_valid_arg(args))
		return (GENERAL_ERRORS);
	if (!(path = set_path(args[1])))
		return (malloc_error());
	if (chdir(path) == -1)
	{
		put_error_msg(path);
		free(path);
		return (GENERAL_ERRORS);
	}
	free(path);
	if (change_env_vars() == ERROR)
		return (malloc_error());
	if (!(new_pwd = ft_strdup(search_env_node("PWD")->value)))
		return (malloc_error());
	free(g_pwd);
	g_pwd = new_pwd;
	return (SUCCEEDED);
}
