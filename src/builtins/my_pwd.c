#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "constants.h"

void my_pwd(char **args)
{
	char *pwd;

	(void)args;
	pwd = getcwd(NULL, 0);	// note:エラー処理
	ft_putendl_fd(pwd, STD_OUT);
	free(pwd);
}