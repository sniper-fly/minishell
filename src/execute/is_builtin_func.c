#include "utils.h"
#include "struct/t_bool.h"

extern const char *g_builtin_func_names[];

t_bool	is_builtin_func(char *cmd)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if(!ft_strcmp((char *)g_builtin_func_names[i], cmd))
			return (TRUE);
		++i;
	}
	return (FALSE);
}
