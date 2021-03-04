/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:18 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:51:18 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			exit(malloc_error());
	}
	else
	{
		if (!(path = ft_strjoin(homedir_path, &arg[1])))
			exit(malloc_error());
	}
	return (path);
}

static char		*set_path(char *arg)
{
	char	*path;

	if (!arg || arg[0] == '~')
		path = replace_homedir_with_path(arg);
	else
	{
		if (!(path = ft_strdup(arg)))
			exit(malloc_error());
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
	path = set_path(args[1]);
	if (chdir(path) == -1)
	{
		put_error_msg(path);
		free(path);
		return (GENERAL_ERRORS);
	}
	free(path);
	change_env_vars();
	if (!(new_pwd = ft_strdup(search_env_node("PWD")->value)))
		exit(malloc_error());
	free(g_pwd);
	g_pwd = new_pwd;
	return (SUCCEEDED);
}
