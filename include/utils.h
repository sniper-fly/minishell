#ifndef UTILS_H
#define UTILS_H

#include "struct/env_list.h"

void		ft_perror(char *str);
void		putchar_times_fd(char ch, int times, int fd);

t_env_list *make_new_env_node(char *envp_i);


#endif
