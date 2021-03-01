#include "libft.h"
#include "utils.h"
#include "constants.h"

void	put_error_msg(char *file_path)
{
	ft_putstr_fd("minishell: cd: ", STD_ERR);
	ft_perror(file_path);
}
