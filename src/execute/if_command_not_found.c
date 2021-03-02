#include <stdlib.h>
#include "libft.h"
#include "constants.h"
#include "exit_status.h"

void	if_command_not_found(char *cmd_path)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(cmd_path, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd("command not found", STD_ERR);
	exit(COMMAND_NOT_FOUND);
}
