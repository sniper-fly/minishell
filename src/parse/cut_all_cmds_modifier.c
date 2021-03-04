/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_all_cmds_modifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:49:46 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:49:47 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "utils.h"

char		**cut_all_cmds_modifier(char **raw_cmds)
{
	char	**cmds;
	int		i;

	cmds = ft_calloc(sizeof(char**), count_string_arr_row(raw_cmds) + 1);
	i = 0;
	while (raw_cmds[i])
	{
		cmds[i] = cut_modifier(raw_cmds[i]);
		i++;
	}
	return (cmds);
}
