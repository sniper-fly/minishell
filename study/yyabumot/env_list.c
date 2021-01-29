#include <stdio.h>
#include "libft/libft.h"
#include "env_list.h"

t_env_list *env_list;

char **get_path_array(void)
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

char **get_env_array(void)
{
	int i;
	int count;
	char **env;
	char *tmp;
	t_env_list *env_var;

	count = 0;
	env_var = env_list->next;
	while(env_var->key){
		++count;
		env_var = env_var->next;
	}
	i = 0;
	env = malloc(sizeof(char *)*(count+1));	// TODO:エラー処理
	env_var = env_list->next;
	while(env_var->key){
		tmp = ft_strjoin(env_var->key, "=");
		env[i] = ft_strjoin(tmp, env_var->value);
		++i;
		env_var = env_var->next;
		free(tmp);
	}
	env[i] = NULL;
	return env;
}

void make_env_list(char **envp)
{
	int i;
	t_env_list *new;
	char **splitted;

	i = 0;
	env_list = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
	env_list->key = NULL;
	env_list->value = NULL;
	env_list->prev = NULL;
	env_list->next = NULL;
	while(envp[i])
	{
		new = malloc(sizeof(t_env_list));	// TODO:mallocエラー処理
		splitted = ft_split(envp[i], '=');
		new->key = splitted[0];
		new->value = splitted[1];
		free(splitted);
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