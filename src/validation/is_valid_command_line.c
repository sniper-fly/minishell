#include "validation.h"
#include "struct/t_bool.h"
#include "constants.h"

static t_bool	is_cmd_line_terminated_with_bkslsh(char *cmd_line)
{
	int		i;

	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == BACK_SLASH)
		{
			if (cmd_line[i + 1] == '\n')
			{
				put_syntax_error_message(
					"terminating with backslash is forbidden.");
				return (TRUE);
			}
			i += 2;
			continue ;
		}
		i++;
	}
	return (FALSE);
}

t_bool	is_valid_command_line(char *cmd_line)
{
	if (is_cmd_line_terminated_with_bkslsh(cmd_line))
		return (FALSE);
	if (!is_valid_char_code(cmd_line))
		return (FALSE);
	if (!is_valid_meta_and_redirect(cmd_line))
		return (FALSE);
	if (!is_valid_quote(cmd_line))
		return (FALSE);
	return (TRUE);
}
