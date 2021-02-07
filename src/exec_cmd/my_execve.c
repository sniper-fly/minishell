#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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

	fd = open(command_path, O_WRONLY);
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

static void check_if_the_full_path_is_valid(char *path)
{
	if(open(path, O_RDWR) == -1 && (errno == EISDIR || errno == ENOENT)){
		ft_putstr_fd("minishlell: ", STD_ERR);
		ft_putstr_fd(path, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
		ft_putendl_fd(strerror(errno), STD_ERR);
		exit(1);
	}
}

void		my_execve(char **cmd)
{
	int		i;
	char	**path_db_ptr;
	char	**envp;
	char	*command_path;

	envp = get_env_array();
	if(cmd[0][0] == '/')
		check_if_the_full_path_is_valid(cmd[0]);
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
			if (execve(command_path, cmd, envp) == ERROR)
				occur_an_error_at_execve();
		}
		free(command_path);
		++i;
	}
	ft_putstr_fd(cmd[0], STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd("command not found", STD_ERR);
	exit(1);
}

#ifdef MY_EXECVE_C

#include <sys/wait.h>

static void exec_test(char **cmd)
{
	if(fork())
		wait(NULL);
	else{
		my_execve(cmd);
		exit(0);
	}
}

int main(int argc, char *argv[], char *envp[])
{
	char *cmd[] = {"ls", "-l", NULL};
	
	char *cmd1[] = {"/bin/", "-l", NULL};
	// ディレクトリを指定

	char *cmd2[] = {"/bin/", "-l", NULL};
	// ディレクトリを指定

	char *cmd3[] = {"実行権限がないファイル", "-l", NULL};
	// 実行権限がないファイル

	char *cmd4[] = {"/not/exist", "-l", NULL};
	//存在しないファイル

	char *cmd5[] = {"notexist", "-l", NULL};
	//存在しないファイル
	argc += 0;
	argv[0][0] = 'A';
	create_env_list(envp);
	exec_test(cmd);
	exec_test(cmd1);
	exec_test(cmd2);
	exec_test(cmd3);
	exec_test(cmd4);
	exec_test(cmd5);
}

#endif