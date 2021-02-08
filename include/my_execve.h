#ifndef MY_EXECVE_H
#define MY_EXECVE_H

char	*get_command_path(char *cmd, char *path_ptr);
void	my_execve(char **cmd);

#endif