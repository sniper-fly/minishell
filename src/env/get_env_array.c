#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "struct/env_list.h"
#include <signal.h>

extern volatile sig_atomic_t			g_status;
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

static char	*make_env_str(t_env_list *env_var)
{
	char	*tmp;
	char	*env_var_str;

	if (!(tmp = ft_strjoin(env_var->key, "=")))
		exit(malloc_error());
	if (env_var->value)
	{
		if (!(env_var_str = ft_strjoin(tmp, env_var->value)))
			exit(malloc_error());
	}
	else
	{
		if (!(env_var_str = ft_strdup(tmp)))
			exit(malloc_error());
	}
	free(tmp);
	return (env_var_str);
}

char		**get_env_array(void)
{
	int			i;
	char		**env;
	t_env_list	*env_var;

	if (!(env = malloc(sizeof(char *) * (count_env_list() + 1))))
		exit(malloc_error());
	i = 0;
	env_var = g_env_list->next;
	while (env_var->key)
	{
		env[i] = make_env_str(env_var);
		++i;
		env_var = env_var->next;
	}
	env[i] = NULL;
	return (env);
}
