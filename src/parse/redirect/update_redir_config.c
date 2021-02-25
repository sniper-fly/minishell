#include "struct/redir_mode.h"
#include "struct/process.h"
#include <fcntl.h>
#include <stdlib.h>

void		update_redir_config(
	t_process *redir_config, char *redir_filename, t_redir_mode *redir_mode)
{
	int		red_flag_bit;

	if (redir_mode->mode_bit & REDIR_IN)
	{
		free(redir_config->red_in_file_name);
		redir_config->red_in_file_name = redir_filename;
		return ;
	}
	if (redir_mode->mode_bit & REDIR_APPEND)
		red_flag_bit = O_APPEND | O_CREAT | O_RDWR;
	else
		red_flag_bit = O_TRUNC | O_CREAT | O_RDWR;
	if (redir_mode->mode_bit & REDIR_OUT)
	{
		free(redir_config->red_out_file_name);
		redir_config->red_out_file_name = redir_filename;
		redir_config->red_out_mode = red_flag_bit;
	}
	else if (redir_mode->mode_bit & REDIR_ERR)
	{
		free(redir_config->red_err_file_name);
		redir_config->red_err_file_name = redir_filename;
		redir_config->red_err_mode = red_flag_bit;
	}
}
