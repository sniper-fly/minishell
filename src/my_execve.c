#include <unistd.h>
#include <fcntl.h>
#include "utils.h"
#include "libft.h"
#include "struct/data_list.h"
#include "struct/env_list.h"

t_env_list	*env_list;

int		my_execve(t_cmd_list *cmd)
{
	int		i;
	int		fd;
	char	**arguments;	
	char	**path_db_ptr;
	char	**command_path;

	//1)envlstからPATHを取得し、PATHをsplitして二次元配列を作る。
	path_db_ptr = get_path_array();

	i = 0;
	while(path_db_ptr[i]){
		command_path = ft_strjoin(path_db_ptr[i], cmd->arg[0]);	// TODO:エラー処理
		//2)prefixをつけてファイルが存在するか（openできるか）検索
		if((fd = open(command_path, O_RDONLY)) != -1){
			//3)ファイルが見つかったらprefixをつけてarguments二次元ポインタに格納する
			free(command_path);
			return (execve(command_path, arguments ,env_list));
		}
		free(command_path);
	}
}