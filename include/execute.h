#ifndef EXEC_CMD_H
#define EXEC_CMD_H

#include "struct/process.h"

void	exec_cmds(t_process *procs);
void	my_execve(char **cmd);
void	exec_tasks(char ***tasks);

#endif