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

static int	set_pwd(char **args_for_my_export)
{
	char		*pwd;
	t_env_list	*pwd_node;

	if (!(pwd = getcwd(NULL, 0)) && errno == ENOENT)
	{
		put_error_msg(NULL);
		pwd_node = search_env_node("PWD");	// note:if no exist
		if (pwd_node->value[ft_strlen(pwd_node->value) - 1] == '/')
		{
			if (!(pwd = ft_strjoin(pwd_node->value, ".")))
				return (ERROR);
		}
		else
		{
			if (!(pwd = ft_strjoin(pwd_node->value, "/.")))
				return (ERROR);
		}
	}
	if (!(args_for_my_export[1] = ft_strjoin("PWD=", pwd)))
	{
		free_string_arr(args_for_my_export);
		return (ERROR);
	}
	free(pwd);
	return (SUCCEEDED);
}

static int	set_old_pwd(char **args_for_my_export)
{
	t_env_list	*pwd_node;

	if ((pwd_node = search_env_node("PWD")) != g_env_list)
	{
		if (!(args_for_my_export[2] = ft_strjoin("OLDPWD=", pwd_node->value)))
			return (ERROR);
	}
	else
		args_for_my_export[2] = NULL;
	return (SUCCEEDED);
}


static int	change_env_vars(void)
{
	char		**args_for_my_export;

	if (!(args_for_my_export = malloc(sizeof(char *) * 4)))
		return (ERROR);
	if (!(args_for_my_export[0] = ft_strdup("export")))
	{
		free_string_arr(args_for_my_export);
		return (ERROR);
	}
	if (set_pwd(args_for_my_export) == ERROR
	|| set_old_pwd(args_for_my_export) == ERROR)
	{
		free_string_arr(args_for_my_export);
		return (ERROR);
	}
	args_for_my_export[3] = NULL;
	my_export(args_for_my_export);
	free_string_arr(args_for_my_export);
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
	char	*path;

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
	if (change_env_vars() == ERROR)
		return (malloc_error());
	return (SUCCEEDED);
}
