#include <unistd.h>
#include <fcntl.h>
#include "constants.h"
#include "struct/process.h"

int			open_redir_file(char *redir_filename, t_process *redir_config)
{
	int		open_flag;
	int		fd;

	if (redir_config->red_in_file_name)
	{
		open_flag = O_RDONLY;
		fd = open(redir_filename, open_flag);
		if (fd == ERROR)
			return (ERROR);
		close(fd);
		return (SUCCESS);
	}
	else if (redir_config->red_out_file_name)
		open_flag = redir_config->red_out_mode;
	else if (redir_config->red_err_file_name)
		open_flag = redir_config->red_err_mode;
	fd = open(redir_filename, open_flag, 0644);
	if (fd == ERROR)
		return (ERROR);
	close(fd);
	return (SUCCESS);
}
