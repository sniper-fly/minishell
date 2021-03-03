#include "struct/t_bool.h"
#include "constants.h"
#include "validation.h"

t_bool	is_cmd_line_terminated_with_bkslsh(char *cmd_line)
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
