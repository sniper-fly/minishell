#include <unistd.h>
#include <fcntl.h>
#include "constants.h"
#include "struct/process.h"

int			open_redir_file(char *redir_filename, t_process *redir_config)
{
	int		open_flag;
	int		open_result;

	if (redir_config->red_in_file_name)
		open_flag = O_RDONLY;
	else if (redir_config->red_out_file_name)
		open_flag = redir_config->red_out_mode;
	else if (redir_config->red_err_file_name)
		open_flag = redir_config->red_err_mode;
	open_result = open(redir_filename, open_flag, 0644);
	if (open_result == ERROR)
		return (ERROR);
	return (SUCCESS);
}
