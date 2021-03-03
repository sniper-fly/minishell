#include "validation.h"
#include "struct/t_bool.h"
#include "constants.h"

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
