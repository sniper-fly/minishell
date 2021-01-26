/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 08:44:45 by yyabumot          #+#    #+#             */
/*   Updated: 2020/06/30 12:15:42 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit(long int n)
{
	int digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		++digit;
	}
	return (digit);
}

char		*ft_itoa(int n)
{
	int			i;
	int			flag;
	long int	nbr;
	char		*num;

	flag = 0;
	nbr = (long int)n;
	if (nbr < 0)
	{
		flag = 1;
		nbr *= -1;
	}
	if (!(num = (char *)malloc(sizeof(char) * (digit(nbr) + flag + 1))))
		return (NULL);
	i = digit(nbr) + flag + 1 - 1;
	num[i] = '\0';
	while (0 + flag <= i)
	{
		--i;
		num[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (flag == 1)
		num[0] = '-';
	return (num);
}
