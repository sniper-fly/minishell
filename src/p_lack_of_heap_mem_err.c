#include "exit_status.h"
#include "constants.h"
#include "utils.h"
#include "libft.h"

int		p_lack_of_heap_mem_err(void)
{
	ft_perror("minishell");
	ft_putendl_fd("You do not to have enough heap memory.", STD_ERR);
	return (GENERAL_ERRORS);
}
