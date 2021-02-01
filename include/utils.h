#ifndef UTILS_H
#define UTILS_H

#include "struct/env_list.h"

void		ft_perror(char *str);
int			ft_strcmp(char *s1, char *s2);

t_env_list *make_new_env_node(char *envp_i);


#endif
