#ifndef DEBUG_H
# define DEBUG_H
# include "struct/process.h"

void		show_string_arr(char **strings);
void		show_procs(t_process **procs);
t_process	**generate_simple_procs(char *line);
void		show_tasks(char ***tasks);
void		old_free_procs(t_process **procs);
void		exec_cmd_for_debug(t_process **procs);
void		show_proc_property(t_process *proc);

#endif
