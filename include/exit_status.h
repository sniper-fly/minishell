/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:47:29 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:47:30 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STATUS_H
# define EXIT_STATUS_H

# define SUCCEEDED 0
# define GENERAL_ERRORS 1
# define SYNTAX_ERROR 2
# define MISUSE_OF_SHELL_BUILTINS 2
# define COMMAND_CANNOT_EXECUTE 126
# define COMMAND_NOT_FOUND 127
# define STAT_INTERRUPTION 130
# define STAT_QUIT 131

#endif
