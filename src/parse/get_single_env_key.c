#include "utils.h"
#include "libft.h"
#include "parse.h"
#include "struct/t_bool.h"
#include "constants.h"

static t_bool	is_env_end_char(char ch)
{
	if (ch == BACK_SLASH || ft_isspace(ch) || ch == DOUBLE_QUOTE ||
		ch == SINGLE_QUOTE || ch == '$' || ch == '\0')
	{
		return (TRUE);
	}
	return (FALSE);
}

/*
** str[idx]から、環境変数の終端までの文字列を返却する
*/
char			*get_single_env_key(char *str, int idx)
{
	char	*single_envkey;
	int		buf_size;
	int		i;

	if (str[idx] == '?')
		return (ft_strdup("?"));
	buf_size = BUF_LEN;
	single_envkey = ft_calloc(sizeof(char), buf_size); //TODO:
	// if (str[idx] == '{')の場合は余裕があったらやる
	i = 0;
	while (!is_env_end_char(str[idx]))
	{
		single_envkey =
			auto_resize_cpy(single_envkey, i, &buf_size, str[idx]);
		idx++;
		i++;
	}
	return (single_envkey);
}
