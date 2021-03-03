#include "libft.h"
#include "validation.h"
#include "struct/t_bool.h"

static t_bool	is_cmd_line_terminated_by_bkslsh(char *cmd_line)
{
	if (2 <= ft_strlen(cmd_line))
	{
		if (cmd_line[ft_strlen(cmd_line) - 2] == '\\')
		{
			if (ft_strlen(cmd_line) == 2)
			{
				put_syntax_error_message("multiple command line is forbidden");
				return (TRUE);
			}
			if (cmd_line[ft_strlen(cmd_line) - 3] != '\\')
			{
				put_syntax_error_message("multiple command line is forbidden");
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

t_bool	is_valid_command_line(char *cmd_line)
{
	if (is_cmd_line_terminated_by_bkslsh(cmd_line))
		return (FALSE);
	if (!is_valid_char_code(cmd_line))
		return (FALSE);
	if (!is_valid_meta_and_redirect(cmd_line))
		return (FALSE);
	if (!is_valid_quote(cmd_line))
		return (FALSE);
	return (TRUE);
}
