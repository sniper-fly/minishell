#ifndef EXEC_CMD_H
#define EXEC_CMD_H

#include "struct/t_bool.h"
#include "struct/process.h"

t_bool is_builtin_func(char *cmd);
void	exec_cmds(t_process *procs);
void	my_execve(char **cmd, char **envp);
void	exec_tasks(char ***tasks);
void	close_and_dup_fds_in_child_proc(int i, int **pipe_fd, t_process *procs);
void close_and_dup_fds_to_redirect(t_process *proc);
int **create_pipe_fd_array(t_process *procs);
void free_pipe_fd_array(int **pipe_fd, t_process *procs);
int	count_procs(t_process *procs);
void	if_command_not_found(char *cmd_path);
char	*join_cmd_to_path(char *cmd, char *path_ptr);


#endif