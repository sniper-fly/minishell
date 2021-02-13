#ifndef ENV_CTRL_H
#define ENV_CTRL_H

#include "struct/env_list.h"

char **get_path_array(void);
char **get_env_array(void);
void create_env_list(char **envp);
t_env_list *make_new_env_node(char *raw_env_var);
int		ft_strcmp(char *s1, char *s2);
t_env_list *search_env_node(char *search_key);

#endif
