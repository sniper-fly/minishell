/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_fail_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:24 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:52:25 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_status.h"

int		redir_fail_cmd(char **args)
{
	(void)args;
	return (GENERAL_ERRORS);
}
