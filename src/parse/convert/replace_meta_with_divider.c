/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_meta_with_divider.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:57 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:52:57 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "constants.h"

void		replace_meta_with_divider(char *line, char rplced_ch)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == SINGLE_QUOTE)
		{
			skip_until_end_single_quote(line, &i);
			continue ;
		}
		else if (line[i] == DOUBLE_QUOTE)
		{
			skip_until_end_double_quote(line, &i);
			continue ;
		}
		else if (line[i] == BACK_SLASH && line[i + 1] == rplced_ch)
		{
			i += 2;
			continue ;
		}
		if (line[i] == rplced_ch)
			line[i] = DIVIDER;
		i++;
	}
}
