/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full_of_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:53:31 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:53:31 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct/t_bool.h"
#include "utils.h"

t_bool		is_full_of_space(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
