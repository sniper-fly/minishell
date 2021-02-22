#include "parse.h"
#include "libft.h"
#include "utils.h"

char		*get_redirect_file(char *str, int i, int mode_bit)
{
	int		start;
	int		filename_len;

	i += (mode_bit & REDIR_APPEND) ? 2 : 1; //append以外は1をプラス
	skip_space_idx(str, &i);
	start = i;
	filename_len = 0;
	while (!(str[i] == '\0' || ft_isspace(str[i])
			|| str[i] == '<' || str[i] == '>'))
	{
		filename_len++;
		i++;
	}
	return (ft_substr(str, start, filename_len)); //TODO:
}
