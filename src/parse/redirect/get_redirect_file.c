#include "parse.h"
#include "libft.h"
#include "utils.h"
#include "constants.h"

char		*get_redirect_file(char *str, int i, int mode_bit)
{
	int		start;
	int		filename_len;

	i += (mode_bit & REDIR_APPEND) ? 2 : 1; //append以外は1をプラス
	skip_space_idx(str, &i);
	start = i;
	while (!(str[i] == '\0' || ft_isspace(str[i])
			|| str[i] == '<' || str[i] == '>'))
	{
		if (str[i] == DOUBLE_QUOTE)
		{
			skip_until_end_double_quote(str, &i);
			continue ;
		}
		if (str[i] == SINGLE_QUOTE)
		{
			skip_until_end_single_quote(str, &i);
			continue ;
		}
		if (str[i] == BACK_SLASH)
			i++;
		i++;
	}
	filename_len = i - start;
	return (ft_substr(str, start, filename_len)); //TODO:
}
