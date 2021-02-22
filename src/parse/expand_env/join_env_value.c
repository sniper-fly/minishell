#include "env_ctrl.h"
#include "parse.h"
#include "libft.h"
#include "struct/t_bool.h"
#include <stdlib.h>

extern int	g_status;

static char *join_status_ch(char *expanded_str, int *buflen)
{
	char	*status_ch;
	int		i;

	status_ch = ft_itoa(g_status); //TODO:
	i = 0;
	while (status_ch[i])
	{
		expanded_str = auto_resize_join(expanded_str, buflen, status_ch[i]);
		i++;
	}
	free(status_ch);
	return (expanded_str);
}

char		*join_env_value(char *expanded_str, int *buflen, char *env_key)
{
	char	*env_value;
	int		i;

	if (env_key[0] == '?')
	{
		expanded_str = join_status_ch(expanded_str, buflen);
		return (expanded_str);
	}
	env_value = search_env_node(env_key)->value;
	if (env_value)
	{
		i = 0;
		while (env_value[i])
		{
			expanded_str = auto_resize_join(expanded_str, buflen, env_value[i]);
			i++;
		}
	}
	return (expanded_str);
}
