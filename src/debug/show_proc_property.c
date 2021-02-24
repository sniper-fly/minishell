#include "utils.h"
#include <fcntl.h>
#include "constants.h"
#include "libft.h"
#include "struct/process.h"
#include <stddef.h>
#include "debug.h"

static void	put_file_name(char *str, char *fname)
{
	if (!fname)
		return ;
	ft_putstr_fd(str, STD_OUT);
	ft_putstr_fd(":[", STD_OUT);
	if (fname == NULL)
		fname = "NULL";
	ft_putstr_fd(fname, STD_OUT);
	ft_putstr_fd("]\n", STD_OUT);
}

static void	put_redir_mode(int redir_mode, char *mode)
{
	if (!redir_mode)
		return ;
	ft_putstr_fd(mode, STD_OUT);
	if (redir_mode & O_TRUNC)
		ft_putendl_fd("(OVERWRITE)", STD_OUT);
	if (redir_mode & O_APPEND)
		ft_putendl_fd("(APPEND)", STD_OUT);
}

void		show_proc_property(t_process *proc)
{
	if (proc == NULL)
		return ;
	ft_putstr_fd("cmd:", STD_OUT);
	show_string_arr(proc->cmd);
	pendl();
	put_file_name("redir in fname", proc->red_in_file_name);
	put_file_name("redir out fname", proc->red_in_file_name);
	put_redir_mode(proc->red_out_mode, "stdout mode");
	put_file_name("redir err fname", proc->red_in_file_name);
	put_redir_mode(proc->red_err_mode, "stderr mode");
	pendl();
}
