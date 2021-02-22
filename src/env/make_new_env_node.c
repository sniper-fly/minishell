#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "struct/t_bool.h"
#include "struct/env_list.h"

extern int g_status;

static char	*get_new_env_value(char *replica_of_arg)
{
	char	*value;
	char	*equal_ptr;

	if ((equal_ptr = ft_strchr(replica_of_arg, '=')))
	{
		if (!(value = ft_strdup(equal_ptr + 1)))
			return (NULL);
	}
	else
		value = NULL;
	return (value);
}

static char	*get_new_env_key(char *arg)
{
	char	*key;
	char	*equal_ptr;

	if ((equal_ptr = ft_strchr(arg, '=')))
	{
		if (!(key = ft_substr(arg, 0, (size_t)(equal_ptr - arg))))
			return (NULL);
	}
	else
	{
		if (!(key = ft_strdup(arg)))
			return (NULL);
	}
	return (key);
}

t_env_list	*make_new_env_node(char *arg)
{
	t_env_list	*new;

	if (!(new = malloc(sizeof(t_env_list))))
		return (NULL);
	if (!(new->key = get_new_env_key(arg)))
	{
		free(new);
		return (NULL);
	}
	if (!(new->value = get_new_env_value(arg)))
	{
		free_env_node(new);
		return (NULL);
	}
	if (!is_valid_env_key(new->key))
	{
		free_env_node(new);
		return (NULL);
	}
	return (new);
}
