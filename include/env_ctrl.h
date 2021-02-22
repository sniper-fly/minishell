#ifndef ENV_CTRL_H
#define ENV_CTRL_H

#include "struct/t_bool.h"
#include "struct/env_list.h"

char **get_path_array(void);
char **get_env_array(void);
int create_env_list(char **envp);
t_env_list *make_new_env_node(char *raw_env_var);
t_env_list *search_env_node(char *search_key);
void free_env_node(t_env_list *env_node);
t_bool is_valid_env_key(char *key);


#endif
