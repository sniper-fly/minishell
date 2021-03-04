/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:21 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:51:22 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "constants.h"

void	put_error_msg(char *file_path)
{
	ft_putstr_fd("minishell: cd: ", STD_ERR);
	ft_perror(file_path);
}
