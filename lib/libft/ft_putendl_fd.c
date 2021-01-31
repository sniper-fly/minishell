/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:05:06 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/11 12:20:37 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	ft_putendl_fd("hogehogegaa", 1);
** 	ft_putendl_fd("hogehogegaa", 1);
** 	return (0);
** }
*/
