#include <stdio.h>
#include "libft/libft.h"
#include "env_list.h"

t_env_list *env_list;

char **path_to_array(void)
{
	t_env_list *tmp;
	char **path;

	tmp = env_list->next;
	while(tmp->key){
		if(!ft_strncmp(tmp->key, "PATH", ft_strlen(tmp->key)))
			break;
		tmp = tmp->next;
	}
	path = ft_split(tmp->value, ':');
	return path;
}

char **env_to_array(void)
{
	int i;
	int count;
	char **env;
	t_env_list *tmp;

	count = 0;
	tmp = env_list->next;
	while(tmp->key){
		++count;
		tmp = tmp->next;
	}
	i = 0;
	env = malloc(sizeof(char *)*(count+1));
	tmp = env_list->next;
	while(tmp->key){
		env[i] = ft_strjoin(ft_strjoin(tmp->key, "="), tmp->value);	// memory leak?
		++i;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return env;
}

void make_env_list(char **envp)
{
	int i;
	t_env_list *new;
	char **tmp;

	i = 0;
	env_list = malloc(sizeof(t_env_list));
	env_list->key = NULL;
	env_list->value = NULL;
	env_list->prev = NULL;
	env_list->next = NULL;
	while(envp[i])
	{
		new = malloc(sizeof(t_env_list));
		tmp = ft_split(envp[i], '=');
		new->key = ft_strdup(tmp[0]);
		new->value = ft_strdup(tmp[1]);
		new->next = env_list;
		if(!(env_list->next)){
			env_list->next = new;
			new->prev = env_list;
		}else{
			env_list->prev->next = new;
			new->prev = env_list->prev;
		}
		env_list->prev = new;
		++i;
	}
}