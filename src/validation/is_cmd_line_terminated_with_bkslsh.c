/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_line_terminated_with_bkslsh.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:05:44 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:06:46 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct/t_bool.h"
#include "constants.h"
#include "validation.h"

t_bool	is_cmd_line_terminated_with_bkslsh(char *cmd_line)
{
	int		i;

	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == BACK_SLASH)
		{
			if (cmd_line[i + 1] == '\n')
			{
				put_syntax_error_message(
					"terminating with backslash is forbidden.");
				return (TRUE);
			}
			i += 2;
			continue ;
		}
		i++;
	}
	return (FALSE);
}
