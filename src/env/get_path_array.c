#include <stdio.h>
#include "libft.h"
#include "utils.h"
#include "struct/env_list.h"

extern t_env_list *g_env_list;

char **get_path_array(void)
{
	char **path;
	t_env_list *tmp;

	tmp = g_env_list->next;
	while(tmp->key){
		if(!ft_strcmp(tmp->key, "PATH"))
			break;
		tmp = tmp->next;
	}
	path = ft_split(tmp->value, ':');	// TODO:エラー処理
	return path;
}

