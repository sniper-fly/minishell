#include "validation.h"
#include "struct/t_bool.h"

static t_bool	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_closed_quote(char **cmd_line, char kind_of_quote)
{
	++(*cmd_line);
	while (TRUE)
	{
		if (!(**cmd_line))
			return (FALSE);
		if (**cmd_line == '\\')
		{
			++(*cmd_line);
			if (!(**cmd_line))
				return (FALSE);
			if (**cmd_line == '\"')
			{
				++(*cmd_line);
				continue;
			}
		}
		if (kind_of_quote == **cmd_line)
			break;
		++(*cmd_line);
	}
	return (TRUE);
}

t_bool			is_valid_quote(char *cmd_line)
{
	char	kind_of_quote;

	while (*cmd_line)
	{
		if(is_quote(*cmd_line))
		{
			kind_of_quote = *cmd_line;
			if (!is_closed_quote(&cmd_line, kind_of_quote))
			{
				put_syntax_error_message("quotation is not closed");
				return (FALSE);
			}
		}
		++cmd_line;
	}
	return (TRUE);
}