#include "libft.h"
#include "constants.h"
#include "exit_status.h"

int	malloc_error(void)
{
	ft_putendl_fd("minishell: malloc error", STD_ERR);
	return (GENERAL_ERRORS);
}
