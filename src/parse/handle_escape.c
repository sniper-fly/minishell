#include "parse.h"
#include "constants.h"
#include "libft.h"
#include <stdlib.h>

char	*handle_escape( char *expanded_str, int *buflen, char *str, int *i)
{
	if (str[*i] == BACK_SLASH)
	{
		expanded_str = handle_backslash(expanded_str, buflen, str, i);
		return (expanded_str);
	}
	else if (str[*i] == SINGLE_QUOTE)
	{
		expanded_str = handle_single_quote(expanded_str, buflen, str, i);
		return (expanded_str);
	}
	// DOUBLE_QUOTE
	expanded_str = handle_double_quote(expanded_str, buflen, str, i);
	return (expanded_str);
}

char	*handle_backslash(char *expanded_str, int *buflen, char *str, int *i)
{
	expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
	expanded_str = auto_resize_join(expanded_str, buflen, str[*i + 1]);
	*i += 2;
	return (expanded_str);
}

char	*handle_double_quote(char *expanded_str, int *buflen, char *str, int *i)
{
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
			expanded_str = interpret_envvar(expanded_str, buflen, str, i);
			continue ;
		}
		expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
		(*i)++;
	}
	expanded_str = auto_resize_join(expanded_str, buflen, str[*i]);
	(*i)++;
	return (expanded_str);
}

char	*handle_single_quote(char *expanded_str, int *buflen, char *str, int *i)
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
