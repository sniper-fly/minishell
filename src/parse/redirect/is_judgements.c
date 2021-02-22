#include <stdlib.h>
#include "utils.h"
#include "struct/t_bool.h"
#include "parse.h"
#include "libft.h"
#include "constants.h"

//strtrimしてもなお、空白が残っている場合。エスケープあり。
t_bool		is_ambiguous_err(char *redir_expanded)
{
	char	*trimmed;
	int		i;

	trimmed = ft_strtrim(redir_expanded, " "); //TODO:
	i = 0;
	while (trimmed[i])
	{
		if (ft_isspace(trimmed[i]))
			return (TRUE);
		if (trimmed[i] == SINGLE_QUOTE)
		{
			skip_until_end_single_quote(trimmed, &i);
			continue ;
		}
		if (trimmed[i] == DOUBLE_QUOTE)
		{
			skip_until_end_double_quote(trimmed, &i);
			continue ;
		}
		if (trimmed[i] == BACK_SLASH)
			i++;
		i++;
	}
	free(trimmed);
	return (FALSE);
}
