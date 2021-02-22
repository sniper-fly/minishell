#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "struct/env_list.h"

extern int			g_status;
extern t_env_list	*g_env_list;

static int	count_env_list(void)
{
	int			count;
	t_env_list	*env_var;

	count = 0;
	env_var = g_env_list->next;
	while (env_var->key)
	{
		++count;
		env_var = env_var->next;
	}
	return (count);
}

static int	set_env_vars(char **env)
{
	int			i;
	char		*tmp;
	t_env_list	*env_var;

	env_var = g_env_list->next;
	while (env_var->key)
	{
		if (!(tmp = ft_strjoin(env_var->key, "=")))
		{
			env[i] = NULL;
			free_string_arr(env);
			return (ERROR);
		}
		if (!(env[i] = ft_strjoin(tmp, env_var->value)))
		{
			free(tmp);
			free_string_arr(env);
			return (ERROR);
		}
		free(tmp);
		++i;
		env_var = env_var->next;
	}
	env[i] = NULL;
	return (SUCCESS);
}

char		**get_env_array(void)
{
	char **env;

	if (!(env = malloc(sizeof(char *) * (count_env_list() + 1))))
		return (NULL);
	if (set_env_vars(env) == ERROR)
		return (NULL);
	return (env);
}
