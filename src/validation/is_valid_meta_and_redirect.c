/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_meta_and_redirect.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:05:58 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:05:59 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "validation.h"
#include "struct/t_bool.h"

static void		skip_normal_char(char **cmd_line)
{
	while (**cmd_line)
	{
		if (is_meta_char(**cmd_line) || is_redirect_char(**cmd_line))
			break ;
		++(*cmd_line);
	}
}

static t_bool	is_started_with_meta(char *cmd_line)
{
	if (is_meta_char(*cmd_line))
	{
		put_syntax_error_message("invalid token");
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_bool	is_terminated_with_redirect(char *cmd_line, t_bool is_redicrect)
{
	if (is_redicrect && !(*cmd_line))
	{
		put_syntax_error_message("invalid redirect");
		return (TRUE);
	}
	return (FALSE);
}

t_bool			is_valid_meta_and_redirect(char *cmd_line)
{
	t_bool	is_redirect;

	skip_space(&cmd_line);
	if (is_started_with_meta(cmd_line))
		return (FALSE);
	while (*cmd_line)
	{
		is_redirect = FALSE;
		skip_normal_char(&cmd_line);
		if (!is_valid_redirect(&cmd_line, &is_redirect))
			return (FALSE);
		if (!is_valid_meta(&cmd_line, is_redirect))
			return (FALSE);
		skip_space(&cmd_line);
		if (is_terminated_with_redirect(cmd_line, is_redirect))
			return (FALSE);
	}
	return (TRUE);
}
