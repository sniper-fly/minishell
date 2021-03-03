#include "libft.h"
#include "validation.h"
#include "struct/t_bool.h"

#include <stdio.h>
t_bool	is_valid_command_line(char *cmd_line)
{
	if (cmd_line[ft_strlen(cmd_line) - 2] == '\\')
	{
		put_syntax_error_message("multiple command line is forbidden");
		return (FALSE);
	}
	if (!is_valid_char_code(cmd_line))
		return (FALSE);
	if (!is_valid_meta_and_redirect(cmd_line))
		return (FALSE);
	if (!is_valid_quote(cmd_line))
		return (FALSE);
	return (TRUE);
}
