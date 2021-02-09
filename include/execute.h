#ifndef EXEC_CMD_H
#define EXEC_CMD_H

#include "struct/process.h"

void	exec_pipes(t_process *procs);
void	my_execve(char **cmd);

#endif