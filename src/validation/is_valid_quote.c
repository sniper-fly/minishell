/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:06:07 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:06:08 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"
#include "struct/t_bool.h"

static t_bool	is_quote(char c)
{
	if (c == '\'' || c == '\"')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_closed_quote(int *i, char *cmd_line, char kind_of_quote)
{
	++(*i);
	while (TRUE)
	{
		if (!(cmd_line[*i]))
			return (FALSE);
		if (cmd_line[*i] == '\\')
		{
			++(*i);
			if (!(cmd_line[*i]))
				return (FALSE);
			if (cmd_line[*i] == '\"')
			{
				++(*i);
				continue ;
			}
		}
		if (kind_of_quote == cmd_line[*i])
			break ;
		++(*i);
	}
	return (TRUE);
}

t_bool			is_valid_quote(char *cmd_line)
{
	int		i;
	char	kind_of_quote;

	i = 0;
	while (cmd_line[i])
	{
		if (is_quote(cmd_line[i]))
		{
			if (0 < i && cmd_line[i - 1] == '\\')
			{
				++i;
				continue ;
			}
			kind_of_quote = cmd_line[i];
			if (!is_closed_quote(&i, cmd_line, kind_of_quote))
			{
				put_syntax_error_message("quotation is not closed");
				return (FALSE);
			}
		}
		++i;
	}
	return (TRUE);
}
