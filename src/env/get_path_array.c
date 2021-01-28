#include <stdio.h>
#include "libft/libft.h"
#include "env_list.h"

char **get_path_array(void)
{
	char **path;
	t_env_list *tmp;

	tmp = env_list->next;
	while(tmp->key){
		if(!ft_strncmp(tmp->key, "PATH", ft_strlen(tmp->key)))
			break;
		tmp = tmp->next;
	}
	path = ft_split(tmp->value, ':');	// TODO:エラー処理
	return path;
}

