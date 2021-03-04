/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_redirect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:06:12 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:06:12 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "struct/t_bool.h"

static t_bool	is_single_redirect(char **cmd_line)
{
	if (**cmd_line == '<')
		++(*cmd_line);
	else if (**cmd_line == '>')
	{
		++(*cmd_line);
		if (**cmd_line == '>')
			++(*cmd_line);
	}
	skip_space(cmd_line);
	if (is_redirect_char(**cmd_line))
		return (FALSE);
	return (TRUE);
}

t_bool			is_valid_redirect(char **cmd_line, t_bool *is_redirect)
{
	if (is_redirect_char(**cmd_line))
	{
		*is_redirect = TRUE;
		if (!is_single_redirect(cmd_line))
		{
			put_syntax_error_message("invalid redirect");
			return (FALSE);
		}
	}
	return (TRUE);
}
