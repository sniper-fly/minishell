#include <unistd.h>
#include "libft.h"

int cd(char *path)
{
	if(chdir(path) == -1){		// TODO:エラー処理
		ft_perror("minishell");
		exit(1);
	}
}