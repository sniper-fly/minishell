#include <stdio.h>
#include "libft.h"
#include "struct/env_list.h"

int count_env_list(void)
{
	int count;
	t_env_list *env_var;

	count = 0;
	env_var = g_env_list->next;
	while(env_var->key){
		++count;
		env_var = env_var->next;
	}
	return count;
}

char **get_env_array(void)
{
	int i;
	char **env;
	char *tmp;
	t_env_list *env_var;

	i = 0;
	env = malloc(sizeof(char *)*(count_env_list()+1));	// TODO:エラー処理
	env_var = g_env_list->next;
	while(env_var->key){
		tmp = ft_strjoin(env_var->key, "=");	// TODO:エラー処理
		env[i] = ft_strjoin(tmp, env_var->value);	// TODO:エラー処理
		free(tmp);
		++i;
		env_var = env_var->next;
	}
	env[i] = NULL;
	return env;
}