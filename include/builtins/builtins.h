/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:46:36 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:46:38 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int		my_echo(char **args);
int		my_export(char **args);
int		my_cd(char **args);
int		my_unset(char **args);
int		my_env(char **args);
int		my_pwd(char **args);
int		my_exit(char **args);
int		my_exit_at_child_process(char **args);
int		redir_fail_cmd(char **args);
void	exec_builtins(char **args);

#endif
