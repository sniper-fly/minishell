#include "libft.h"
#include "constants.h"
#include "exit_status.h"

extern char	*g_pwd;

int	my_pwd(char **args)
{
	(void)args;
	ft_putendl_fd(g_pwd, STD_OUT);
	return (SUCCEEDED);
}
