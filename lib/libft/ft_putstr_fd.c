/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:01:29 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 12:41:28 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr_fd(char *str, int fd)
{
	int		idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		ft_putchar_fd(str[idx], fd);
		idx++;
	}
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	ft_putstr_fd("halleohalo", 1);
** 	return (0);
** }
*/
