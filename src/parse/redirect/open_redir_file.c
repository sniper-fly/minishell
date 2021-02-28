#include <unistd.h>
#include <fcntl.h>
#include "constants.h"
#include "struct/redir_mode.h"
#include "struct/process.h"

int			open_redir_file(
	char *redir_filename, t_process *redir_config, t_redir_mode *current_redir)
{
	int		open_flag;
	int		fd;

	open_flag = 0;
	if (current_redir->mode_bit & REDIR_IN)
	{
		open_flag = O_RDONLY;
		fd = open(redir_filename, open_flag);
		if (fd == ERROR)
			return (ERROR);
		close(fd);
		return (SUCCESS);
	}
	else if (current_redir->mode_bit & REDIR_OUT)
		open_flag = redir_config->red_out_mode;
	else if (current_redir->mode_bit & REDIR_ERR)
		open_flag = redir_config->red_err_mode;
	fd = open(redir_filename, open_flag, 0644);
	if (fd == ERROR)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}
