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
t_bool			is_ambiguous_err(char *redir_expanded)
{
	char	*trimmed;
	int		i;

	trimmed = ft_strtrim(redir_expanded, " "); //TODO:
	i = 0;
	while (trimmed[i])
	{
		if (ft_isspace(trimmed[i]))
		{
			free(trimmed);
			return (TRUE);
		}
		else if (is_escape(trimmed[i]))
		{
			skip_escape_seq(trimmed, &i);
			continue ;
		}
		i++;
	}
	free(trimmed);
	return (FALSE);
}
