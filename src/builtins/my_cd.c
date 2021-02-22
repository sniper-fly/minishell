#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "builtins/builtins.h"

extern t_env_list *g_env_list;

static void	put_error_msg(char *file_path)
{
	ft_putstr_fd("minishell: cd: ", STD_ERR);
	ft_perror(file_path);
}

static int	change_env_vars(void)
{
	char	*pwd;
	char	**args_to_my_export;

	if (!(args_to_my_export = malloc(sizeof(char *) * 4)))
		return (-1);
	if (!(args_to_my_export[0] = ft_strdup("export")))
		return (-1);
	if (!(args_to_my_export[1] =
	ft_strjoin("OLDPWD=", search_env_node("PWD")->value)))
		return (-1);
	pwd = getcwd(NULL, 0);
	if (!(args_to_my_export[2] = ft_strjoin("PWD=", pwd)))
		return (-1);
	args_to_my_export[3] = NULL;
	my_export(args_to_my_export);
	free(pwd);
	free_string_arr(args_to_my_export);
	return (0);
}

static char	*replace_homedir_to_path(char *arg)
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

static char	*set_path(char *arg)
{
	char	*path;

	if (!arg || arg[0] == '~')
	{
		if (!(path = replace_homedir_to_path(arg)))
			return (NULL);
	}
	else
	{
		if (!(path = ft_strdup(arg)))
			return (NULL);
	}
	return (path);
}

int			my_cd(char **args)
{
	char *path;

	if (2 < count_string_arr_row(args))
	{
		ft_putendl_fd("minishell: cd: too many arguments", STD_ERR);
		return (GENERAL_ERRORS);
	}
	if (!args[1] && search_env_node("HOME") == g_env_list)
	{
		ft_putendl_fd("minishell: cd: HOME not set", STD_ERR);
		return (GENERAL_ERRORS);
	}
	if (!(path = set_path(args[1])))
		return (malloc_error());
	if (chdir(path) == -1)
	{
		put_error_msg(path);
		free(path);
		return (GENERAL_ERRORS);
	}
	free(path);
	if (change_env_vars() < 0)
		return (malloc_error());
	return (SUCCEEDED);
}
