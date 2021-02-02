#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "utils.h"
#include "libft.h"
#include "constants.h"
#include "struct/process.h"
#include "struct/env_list.h"
#include <stdlib.h>
#include "env_ctrl.h"

t_env_list	*g_env_list;

static int is_there_execute_file_at(char *command_path)
{
	int		fd;

	fd = open(command_path, O_RDONLY);
	return (fd != ERROR || errno != ENOENT);
}

void		my_execve(t_cmd_list *cmd)
{
	int		i;
	// char	**arguments;	
	char	**path_db_ptr;
	char	*command_path;
	char	*haribote[] = {"haribote", NULL};

	if (is_there_execute_file_at(cmd->arg)){
		if(execve(cmd->arg, haribote, haribote) == ERROR)
		{
			ft_perror("minishell");
			exit(1);
		}
	}
	//1)envlstからPATHを取得し、PATHをsplitして二次元配列を作る。
	i = 0;
	path_db_ptr = get_path_array();	// TODO:free
	while (path_db_ptr[i])
	{
		command_path = ft_strjoin(path_db_ptr[i], cmd->arg);	// TODO:エラー処理
		//2)prefixをつけてファイルが存在するか（openできるか）検索
		if (is_there_execute_file_at(command_path))
		{
			//3)ファイルが見つかったらprefixをつけてarguments二次元ポインタに格納する
			if (execve(command_path, haribote, haribote) == ERROR)
			{
				ft_perror("minishell");
				exit(1); //TODO: exitの値をどうするか要検証
			}
		}
		ft_perror("minishell");
		exit(1); //TODO: exitの値をどうするか要検証
	}
}