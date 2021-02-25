#ifndef UTILS_H
#define UTILS_H

#include "struct/env_list.h"
#include "struct/process.h"

void		ft_perror(char *str);
void		putchar_times_fd(char ch, int times, int fd);
int			count_string_arr_row(char **strings);
void		free_string_arr(char **strings);
void		pendl(void);
int			count_procs(t_process *procs);
int			ft_strcmp(char *s1, char *s2);
int			ft_isspace(char ch);
int			malloc_error(void);

void		free_procs(t_process *procs);
void		free_single_proc(t_process *proc);

#endif
