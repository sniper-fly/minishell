#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include "struct/env_list.h"

static void init_env_list(void)
{
	g_env_list = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	g_env_list->key = NULL;
	g_env_list->value = NULL;
	g_env_list->prev = g_env_list;
	g_env_list->next = g_env_list;
}

void create_env_list(char **envp)
{
	int i;
	t_env_list *new;

	i = 0;
	init_env_list();
	while(envp[i])
	{
		new = make_new_env_node(envp[i]);
		new->next = g_env_list;
		if(!(g_env_list->next)){
			g_env_list->next = new;
			new->prev = g_env_list;
		}else{
			g_env_list->prev->next = new;
			new->prev = g_env_list->prev;
		}
		g_env_list->prev = new;
		++i;
	}
}

#ifdef CREATE_ENV_LIST_C

int	main(int argc, char *argv[], char *envp[])
{
	t_env_list *env_node;

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);
	env_node = g_env_list->next;
	while(env_node != g_env_list)
	{
		printf("%s=%s\n", env_node->key, env_node->value);
		env_node = env_node->next;
	}
}

#endif