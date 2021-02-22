#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/t_bool.h"
#include "struct/env_list.h"

static int	set_new_env_value(char *replica_of_arg, t_env_list *new)
{
	char	*equal_ptr;

	if ((equal_ptr = ft_strchr(replica_of_arg, '=')))
	{
		if (!(new->value = ft_strdup(equal_ptr + 1)))
			return (ERROR);
	}
	else
		new->value = NULL;
	return (SUCCESS);
}

static int	set_new_env_key(char *arg, t_env_list *new)
{
	char	*equal_ptr;

	if ((equal_ptr = ft_strchr(arg, '=')))
	{
		if (!(new->key = ft_substr(arg, 0, (size_t)(equal_ptr - arg))))
			return (ERROR);
	}
	else
	{
		if (!(new->key = ft_strdup(arg)))
			return (ERROR);
	}
	return (SUCCESS);
}

t_env_list	*make_new_env_node(char *arg)
{
	t_env_list	*new;

	if (!(new = malloc(sizeof(t_env_list))))
		return (NULL);
	if (set_new_env_key(arg, new) == ERROR)
	{
		free(new);
		return (NULL);
	}
	if (set_new_env_value(arg, new) == ERROR)
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
