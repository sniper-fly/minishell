#include <stdio.h>
#include "libft.h"
#include "struct/env_list.h"

char **get_path_array(void)
{
	char **path;
	t_env_list *tmp;

	tmp = g_env_list->next;
	while(tmp->key){
		if(!ft_strncmp(tmp->key, "PATH", ft_strlen(tmp->key)))
			break;
		tmp = tmp->next;
	}
	path = ft_split(tmp->value, ':');	// TODO:エラー処理
	return path;
}
