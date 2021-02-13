#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include "constants.h"
#include "struct/t_bool.h"

void			put_syntax_error_message(char *msg)
{
	ft_putstr_fd("minishell: syntax error ", STD_ERR);
	ft_putstr_fd(msg, STD_ERR);
	pendl();
}


t_bool			is_meta_char(char c)
{
	if (c == '|' || c == ';')
		return (TRUE);
	return (FALSE);
}

t_bool			is_redirect_char(char c)
{
	if (c == '<' || c == '>')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r')
		return (TRUE);
	return (FALSE);
}

void			skip_space(char **cmd_line)
{
	while (is_space(**cmd_line))
		++(*cmd_line);
}
