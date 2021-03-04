/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:47:38 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:47:38 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "constants.h"

void	print_prompt(void);
int		p_lack_of_heap_mem_err(void);
t_bool	is_full_of_space(char *line);
t_bool	is_valid_command_line(char *cmd_line);
void	setup_shell(char **line, char **envp);
int		init_pwd(void);

int		read_cmd_line(char *line);
t_bool	is_valid_command_line(char *cmd_line);
char	***convert_line2tasks(char *line);
void	exec_tasks(char ***tasks);
void	free_tasks(char ***tasks);

#endif
