#ifndef MY_EXPORT_H
#define MY_EXPORT_H

#include "struct/env_list.h"

void sort_keys_by_lexical_order(char **env_str_arr);
char *create_env_str(t_env_list *env_node);


void	print_env(void);
t_env_list **create_new_env_nodes_arr(char **args);
void add_new_env_var_to_list(t_env_list *new_env_node);
void my_export(char **args);


#endif