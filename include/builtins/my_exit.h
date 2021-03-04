/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:46:46 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:46:47 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_EXIT_H
# define MY_EXIT_H

long int	ft_atol(const char *str);
int			my_exit(char **args);
int			my_exit_at_child_process(char **args);

#endif
