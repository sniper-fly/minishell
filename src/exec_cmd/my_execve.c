#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/process.h"
#include "struct/env_list.h"

t_env_list	*g_env_list;

static int is_there_execute_file_at(char *command_path)
{
	int		fd;

	fd = open(command_path, O_RDONLY);
	return (fd != ERROR || errno != ENOENT);
}

static char *get_command_path(char *cmd, char *path_ptr)
{
	char *add_slash;
	char *command_path;

	add_slash = NULL;
	if(path_ptr[ft_strlen(path_ptr) - 1] != '/')
	{
		add_slash = ft_strjoin(path_ptr, "/");
		command_path = ft_strjoin(add_slash, cmd);	// TODO:エラー処理
	}
	else
		command_path = ft_strjoin(path_ptr, cmd);
	free(add_slash);
	return (command_path);
}

static void occur_an_error_at_execve(void)
{
	ft_perror("minishell");
	exit(1);	// TODO: exitのステータス要検証
}

void		my_execve(char **cmd)
{
	int		i;
	char	**path_db_ptr;
	char	**envp;
	char	*command_path;

	envp = get_env_array();
	if (is_there_execute_file_at(cmd[0])){
		if(execve(cmd[0], cmd, envp) == ERROR)
			occur_an_error_at_execve();
	}
	//1)envlstからPATHを取得し、PATHをsplitして二次元配列を作る。
	i = 0;
	path_db_ptr = get_path_array();	// TODO:free?
	while (path_db_ptr[i])
	{
		command_path = get_command_path(cmd[0], path_db_ptr[i]);
		//2)prefixをつけてファイルが存在するか（openできるか）検索
		if (is_there_execute_file_at(command_path))
		{
			//3)ファイルが見つかったらprefixをつけてarguments二次元ポインタに格納する
			cmd[0] = command_path;	// TODO:cmd[0]free必要?
			if (execve(command_path, cmd, envp) == ERROR)
				occur_an_error_at_execve();
		}
		free(command_path);
		++i;
	}
	occur_an_error_at_execve();
}

#ifdef MY_EXECVE_C

#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	char *cmd[] = {"ls", "-l", NULL};

	argc += 0;
	argv[0][0] = 'A';
	create_env_list(envp);
	if(fork())
		wait(NULL);
	else{
		my_execve(cmd);
		exit(0);
	}
}

#endif