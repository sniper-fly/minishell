/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str_by_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:50:02 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:50:02 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

static void	replace_with_space(char *str)
{
	int		i;

	replace_meta_with_divider(str, ' ');
	i = 9;
	while (i <= 13)
	{
		replace_meta_with_divider(str, i);
		i++;
	}
}

char		**split_str_by_space(char *str)
{
	char	**raw_cmds;

	replace_with_space(str);
	raw_cmds = ft_split(str, DIVIDER);
	return (raw_cmds);
}
