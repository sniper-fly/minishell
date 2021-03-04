/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:05:49 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:05:50 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "validation.h"
#include "struct/t_bool.h"

t_bool	is_valid_char_code(char *cmd_line)
{
	while (*cmd_line)
	{
		if (!ft_isascii(*cmd_line))
		{
			put_syntax_error_message("non-ASCII character");
			return (FALSE);
		}
		++cmd_line;
	}
	return (TRUE);
}
