#include <stdio.h>
#include "libft.h"
#include "struct/env_list.h"

static void init_env_list(void)
{
	g_env_list = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	g_env_list->key = NULL;
	g_env_list->value = NULL;
	g_env_list->prev = NULL;
	g_env_list->next = NULL;
}

static t_env_list *make_new_env_node(char *envp_i)
{
	t_env_list *new;
	char **splitted;

	new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	splitted = ft_split(envp_i, '=');	// TODO:エラー処理
	new->key = splitted[0];
	new->value = splitted[1];
	free(splitted);
	return new;
}

void make_env_list(char **envp)
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