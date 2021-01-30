#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int my_cd(char *path)
{
	if(chdir(path) == -1){		// TODO:エラー処理
		ft_perror("minishell");
		exit(1);
	}
}

// int main(void)
// {
// 	char *path = "./src";
// 	my_cd(path);
// 	char *cmd[] = {"ls", NULL};
// 	execvp(cmd[0], cmd);
// }