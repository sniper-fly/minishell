#ifndef UTILS_H
#define UTILS_H

#include "struct/env_list.h"

void		ft_perror(char *str);
void		putchar_times_fd(char ch, int times, int fd);
int			count_string_arr_row(char **strings);
void		free_string_arr(char **strings);
void		pendl(void);
void		show_string_arr(char **strings);

t_env_list *make_new_env_node(char *envp_i);


#endif
