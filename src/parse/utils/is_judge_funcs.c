#include <stdlib.h>
#include "utils.h"
#include "struct/t_bool.h"
#include "parse.h"
#include "libft.h"
#include "constants.h"

t_bool			is_escape(char ch)
{
	if (ch == SINGLE_QUOTE || ch == DOUBLE_QUOTE || ch == BACK_SLASH)
		return (TRUE);
	return (FALSE);
}

//strtrimしてもなお、空白が残っている場合。エスケープあり。
t_bool			is_ambiguous_err(char *redir_trimmed)
{
	int		i;

	i = 0;
	while (redir_trimmed[i])
	{
		if (ft_isspace(redir_trimmed[i]))
		{
			return (TRUE);
		}
		else if (is_escape(redir_trimmed[i]))
		{
			skip_escape_seq(redir_trimmed, &i);
			continue ;
		}
		i++;
	}
	return (FALSE);
}
