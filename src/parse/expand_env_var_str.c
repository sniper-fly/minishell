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
