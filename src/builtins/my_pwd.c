#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "exit_status.h"

int	my_pwd(char **args)
{
	char	*pwd;

	(void)args;
	if (!(pwd = getcwd(NULL, 0)))
	{
		ft_putstr_fd("minishell: pwd: ", STD_ERR);
		ft_perror(NULL);
	}
	ft_putendl_fd(pwd, STD_OUT);
	free(pwd);
	return (SUCCEEDED);
}
