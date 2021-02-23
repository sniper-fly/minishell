#include "exit_status.h"
#include "libft.h"
#include "constants.h"
#include "utils.h"
#include <stdlib.h>
#include <errno.h>

static void	p_common_err(char *cause, char *msg)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(cause, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd(msg, STD_ERR);
}

int			p_bad_fd_err(char *fd_str)
{
	p_common_err(fd_str, "Bad file descriptor");
	return (GENERAL_ERRORS);
}

int			p_ambiguous_err(char *str_to_free, char *redir_expanded)
{
	free(str_to_free);
	p_common_err(redir_expanded, "ambiguous redirect");
	return (GENERAL_ERRORS);
}

int			p_open_err(char *str_to_free1, char *str_to_free2, char *filename, int err_number)
{
	free(str_to_free1);
	free(str_to_free2);
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(filename, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	errno = err_number;
	ft_perror(NULL);
	return (err_number);
}
