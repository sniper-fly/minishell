#include <stdlib.h>
#include "libft.h"

char *get_command_path(char *cmd, char *path_ptr)
{
	char *add_slash;
	char *cmd_path;

	add_slash = NULL;
	if(path_ptr[ft_strlen(path_ptr) - 1] != '/')
	{
		add_slash = ft_strjoin(path_ptr, "/");
		cmd_path = ft_strjoin(add_slash, cmd);	// TODO:エラー処理
	}
	else
		cmd_path = ft_strjoin(path_ptr, cmd);
	free(add_slash);
	return (cmd_path);
}

