#ifndef DEBUG_H
#define DEBUG_H
#include "struct/process.h"

void		show_string_arr(char **strings);
void		show_procs(t_process **procs);
t_process	**generate_simple_procs(char *line);
void		show_str_procs(char ***str_procs);

#endif
