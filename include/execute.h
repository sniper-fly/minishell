#ifndef EXEC_CMD_H
#define EXEC_CMD_H

#include "struct/t_bool.h"
#include "struct/process.h"

t_bool is_builtin_func(char *cmd);
void	exec_cmds(t_process *procs);
void	my_execve(char **cmd);
void	exec_tasks(char ***tasks);

#endif