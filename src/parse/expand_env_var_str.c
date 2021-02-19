#include "parse.h"
#include "libft.h"
#include "constants.h"
#include "utils.h"
#include "struct/t_bool.h"
#include <stdlib.h>

// $があり、かつその次の文字が\,space,},\0のいずれかでない
static t_bool	should_interpret_as_envvar(char *str, int i)
{
	if (str[i] == '$' &&
		!((str[i + 1] == BACK_SLASH || ft_isspace(str[i + 1]) ||
		str[i + 1] == '}' || str[i + 1] == '$' || str[i + 1] == '\0' )))
	{
		return (TRUE);
	}
	return (FALSE);
}

char		*handle_backslash(char *expanded_str, int *buflen, char *str, int *i)
{
	expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
	expanded_str = auto_resize_join(expanded_str, buflen, str[*i + 1]);
	*i += 2;
	return (expanded_str);
}

static char		*handle_double_quote(char *expanded_str, int *buflen, char *str, int *i)
{
	char	*env_key;

	expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
	(*i)++;
	while (str[*i] != DOUBLE_QUOTE)
	{
		if (str[*i] == BACK_SLASH)
		{
			expanded_str = handle_backslash(expanded_str, buflen, str, i);
			continue ;
		}
		if (should_interpret_as_envvar(str, *i))
		{
			(*i)++; //$をスキップする
			env_key = get_single_env_key(str, *i);
			expanded_str = join_env_value(expanded_str, buflen, env_key);
			*i += ft_strlen(env_key);
			free(env_key);
			continue ;
		}
		expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
		(*i)++;
	}
	expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
	(*i)++;
	return (expanded_str);
}

static char		*handle_escape_ch(
	char *expanded_str, int *buflen, char *str, int *i)
{
	if (str[*i] == BACK_SLASH)
	{
		expanded_str = handle_backslash(expanded_str, buflen, str, i);
		return (expanded_str);
	}
	else if (str[*i] == SINGLE_QUOTE)
	{
		expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
		(*i)++;
		while (str[*i] != SINGLE_QUOTE)
		{
			expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
			(*i)++;
		}
		expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
		(*i)++;
		return (expanded_str);
	}
	else if (str[*i] == DOUBLE_QUOTE)
	{
		expanded_str = handle_double_quote(expanded_str, buflen, str, i);
		return (expanded_str);
	}
	return (expanded_str);
}

char			*expand_env_var_str(char *str)
{
	char	*expanded_str;
	char	*env_key;
	int		buflen;
	int		i;

	buflen = BUF_LEN;
	expanded_str = ft_calloc(sizeof(char), buflen); //TODO:
	i = 0;
	while (str[i])
	{
		if (str[i] == SINGLE_QUOTE || str[i] == DOUBLE_QUOTE || str[i] == BACK_SLASH)
		{
			expanded_str = handle_escape_ch(expanded_str, &buflen, str, &i);
			continue ;
		}
		if (should_interpret_as_envvar(str, i))
		{
			i++; //$をスキップする
			env_key = get_single_env_key(str, i);
			expanded_str = join_env_value(expanded_str, &buflen, env_key);
			i += ft_strlen(env_key);
			free(env_key);
			continue ;
		}
		expanded_str = auto_resize_join(expanded_str, &buflen, str[i]);
		i++;
	}
	return (expanded_str);
}
