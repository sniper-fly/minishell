/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:09:50 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 12:39:53 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	putnumber(int num, int fd)
{
	if (num < 10)
		ft_putchar_fd(num + '0', fd);
	else
	{
		putnumber(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int num, int fd)
{
	if (num == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	putnumber(num, fd);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	ft_putnbr_fd(134, 1);
** 	printf("\n");
** 	ft_putnbr_fd(INT_MIN, 1);
** 	printf("\n");
** 	ft_putnbr_fd(INT_MAX, 1);
** 	printf("\n");
** 	ft_putnbr_fd(-11123, 1);
** 	return (0);
** }
*/
