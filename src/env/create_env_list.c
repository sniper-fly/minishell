#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/env_list.h"

extern t_env_list	*g_env_list;

static int	init_env_list(void)
{
	if (!(g_env_list = malloc(sizeof(t_env_list))))
	{
		malloc_error();
		return (ERROR);
	}
	g_env_list->key = NULL;
	g_env_list->value = NULL;
	g_env_list->prev = g_env_list;
	g_env_list->next = g_env_list;
	return (SUCCESS);
}

int			create_env_list(char **envp)
{
	int			i;
	t_env_list	*new;

	i = 0;
	if (init_env_list() == ERROR)
		return (ERROR);
	while (envp[i])
	{
		if (!(new = make_new_env_node(envp[i])))
		{
			malloc_error();
			exit(GENERAL_ERRORS);
		}
		new->next = g_env_list;
		g_env_list->prev->next = new;
		new->prev = g_env_list->prev;
		g_env_list->prev = new;
		++i;
	}
	return (SUCCESS);
}
