/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_times_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:50:55 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:50:55 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	putchar_times_fd(char ch, int times, int fd)
{
	int		i;

	i = 0;
	while (i < times)
	{
		ft_putchar_fd(ch, fd);
		i++;
	}
}
