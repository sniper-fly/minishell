/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:57:24 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 17:49:31 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int		ft_isspace(char ch)
{
	if (ch == ' ' || (9 <= ch && ch <= 13))
		return (1);
	return (0);
}

int				ft_atoi(const char *nptr)
{
	size_t	idx;
	int		total;
	int		sign;

	if (ft_strlen(nptr) == 0)
		return (0);
	sign = 1;
	total = 0;
	idx = 0;
	while (ft_isspace(nptr[idx]) == 1)
		idx++;
	if (nptr[idx] == '+')
		idx++;
	else if (nptr[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	while (ft_isdigit(nptr[idx]) == 1)
	{
		total = total * 10 + nptr[idx] - '0';
		idx++;
	}
	return (total * sign);
}

/*
** #include <stdio.h>
** #include <stdlib.h>
** int		main(void)
** {
** 	char hoge[] = "-2147483648";
** 	printf("%d", atoi(hoge));
** 	printf("\n");
** 	printf("%d", ft_atoi(hoge));
** 	return (0);
** }
*/
