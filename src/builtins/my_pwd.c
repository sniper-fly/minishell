/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:17 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:52:18 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "constants.h"
#include "exit_status.h"

extern char	*g_pwd;

int	my_pwd(char **args)
{
	(void)args;
	ft_putendl_fd(g_pwd, STD_OUT);
	return (SUCCEEDED);
}
