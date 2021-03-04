/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 10:12:18 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/02 15:35:37 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	char		mod;

	nbr = (long int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	mod = nbr % 10 + '0';
	if (nbr / 10 > 0)
		ft_putnbr_fd((int)(nbr / 10), fd);
	write(fd, &mod, 1);
}
