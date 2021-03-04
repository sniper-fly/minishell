/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_command_not_found.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:21 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:22 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "constants.h"
#include "exit_status.h"

extern int	g_status;

void	if_command_not_found(char *cmd_path)
{
	ft_putstr_fd("minishell: ", STD_ERR);
	ft_putstr_fd(cmd_path, STD_ERR);
	ft_putstr_fd(": ", STD_ERR);
	ft_putendl_fd("command not found", STD_ERR);
	exit(COMMAND_NOT_FOUND);
}
