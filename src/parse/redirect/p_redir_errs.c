#include "parse.h"
#include "exit_status.h"
#include "libft.h"
#include "constants.h"
#include "utils.h"
#include <stdlib.h>

static void	p_common_err(char *cause, char *msg)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(cause, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd(msg, STD_ERR);
}

int			p_bad_fd_err(char *fd_str, t_process *redir_config)
{
	p_common_err(fd_str, "Bad file descriptor");
	free_single_proc(redir_config);
	free(fd_str);
	return (ERROR);
}

int			p_ambiguous_err(char *raw_redir_fname)
{
	p_common_err(raw_redir_fname, "ambiguous redirect");
	free(raw_redir_fname);
	return (ERROR);
}

int			p_open_err(char *str_to_free1, char *str_to_free2,
	char *redir_filename, t_process *redir_config)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(redir_filename, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_perror(NULL);
	free(str_to_free1);
	free(str_to_free2);
	free_single_proc(redir_config);
	return (ERROR);
}
