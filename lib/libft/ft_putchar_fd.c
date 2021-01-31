/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 12:57:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/09 13:11:21 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar_fd(char ch, int fd)
{
	write(fd, &ch, 1);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	ft_putchar_fd('c', 1);
** 	return (0);
** }
*/
