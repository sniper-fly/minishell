#include "parse.h"
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
	free(fd_str);
	return (ERROR);
}

int			p_ambiguous_err(
	char *str_to_free1, char *str_to_free2, char *redir_expanded)
{
	p_common_err(redir_expanded, "ambiguous redirect");
	free(str_to_free1);
	free(str_to_free2);
	free(redir_expanded);
	return (ERROR);
}

int			p_open_err(char *str_to_free1, char *str_to_free2,
	char *redir_expanded, t_process *redir_config)
{
	char	*file_name;
	int		err_num;

	err_num = errno;
	file_name = cut_modifier(redir_expanded);
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(file_name, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	errno = err_num;
	ft_perror(NULL);
	free(str_to_free1);
	free(str_to_free2);
	free(redir_expanded);
	free(file_name);
	free_single_proc(redir_config);
	return (ERROR);
}
