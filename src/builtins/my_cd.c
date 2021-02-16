#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "env_ctrl.h"
#include "builtins/builtins.h"

static void put_error_msg(char *file_path)
{
	ft_putstr_fd("minishell: cd: ", STD_ERR);
	// if(file_path)
	// {
	// 	ft_putstr_fd(file_path, STD_ERR);
	// 	ft_putstr_fd(": ", STD_ERR);
	// }
	ft_perror(file_path);
	// ft_putendl_fd(msg, STD_ERR);
}

static void change_env_vars(void)
{
	char *pwd;
	char **args_to_my_export;

	args_to_my_export = malloc(sizeof(char *) * 4);	// TODO:エラー処理
	args_to_my_export[0] = ft_strdup("export");	// TODO:エラー処理
	args_to_my_export[1] = ft_strjoin("OLDPWD=", search_env_node("PWD")->value);	// TODO:エラー処理
	pwd = getcwd(NULL, 0);	// エラー処理　
	args_to_my_export[2] = ft_strjoin("PWD=", pwd);	// TODO:エラー処理
	args_to_my_export[3] = NULL;
	my_export(args_to_my_export);
	free(pwd);
	free_string_arr(args_to_my_export);
}

static char *replace_homedir_to_path(char *arg)
{
	char *path;
	char *homedir_path;

	homedir_path = search_env_node("HOME")->value;
	if(!arg || arg[0] == '#')
	{
		path = ft_strdup(homedir_path);	// TODO:エラー処理
	}
	else
	{
		path = ft_strjoin(homedir_path, &arg[1]);
	}
	return (path);
}

void my_cd(char **args)
{
	char *path;

	if(2 < count_string_arr_row(args))
	{
		ft_putendl_fd("minishell: cd: too many arguments", STD_ERR);
		return ;
	}
	if(!args[1] || args[1][0] == '~' || args[1][0] == '#')
		path = replace_homedir_to_path(args[1]);
	else
		path = ft_strdup(args[1]);	// TODO:エラー処理
	if(chdir(path) == -1)
	{
		put_error_msg(args[1]);
		// if(errno == EACCES)
		// 	put_error_msg(args[1], "Permission denied");
		// if(errno == ENOTDIR)
		// 	put_error_msg(args[1], "Not a directory");
		// if(errno == ENOENT)
		// 	put_error_msg(args[1], "No such file or directory");
		free(path);
		return ;
	}
	free(path);
	change_env_vars();
}
