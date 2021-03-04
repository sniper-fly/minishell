/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_string_arr_row.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:50:17 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:50:17 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** If null is sent, segfault
*/

int		count_string_arr_row(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
		i++;
	return (i);
}
