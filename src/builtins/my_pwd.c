#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"

extern t_env_list *g_env_list;

int	my_pwd(char **args)
{
	char		*pwd;
	t_env_list	*pwd_node;

	(void)args;
	if ((pwd_node = search_env_node("PWD")) != g_env_list)
		ft_putendl_fd(pwd_node->value, STD_OUT);
	else
	{
		if (!(pwd = getcwd(NULL, 0)))
		{
			ft_putstr_fd("minishell: pwd: ", STD_ERR);
			ft_perror(NULL);
			return (GENERAL_ERRORS);
		}
		ft_putendl_fd(pwd, STD_OUT);
		free(pwd);
	}
	return (SUCCEEDED);
}
