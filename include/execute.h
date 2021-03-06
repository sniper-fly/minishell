/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:47:25 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:47:26 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "struct/t_bool.h"
# include "struct/process.h"

t_bool	is_builtin_func(char *cmd);
void	exec_cmds(t_process *procs);
void	my_execve(char **cmd, char **envp);
void	exec_tasks(char ***tasks);
void	close_and_dup_fds_in_child_proc(int i, int **pipe_fd, t_process *procs);
void	close_and_dup_fds_to_redirect(t_process *proc);
int		**create_pipe_fd_array(t_process *procs);
void	free_pipe_fd_array(int **pipe_fd, t_process *procs);
int		count_procs(t_process *procs);
void	if_command_not_found(char *cmd_path);
char	*join_cmd_to_path(char *cmd, char *path_ptr);
int		is_there_execute_file_at(char *cmd_path);
void	exit_if_command_path_is_dir(char *cmd_path);
void	check_if_the_full_path_is_valid(char *cmd_path);

#endif
