/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:50:33 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:50:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "constants.h"
#include <string.h>
#include <errno.h>

void		ft_perror(char *str)
{
	if (str != NULL && str[0] != '\0')
	{
		ft_putstr_fd(str, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
	}
	ft_putstr_fd(strerror(errno), STD_ERR);
	ft_putchar_fd('\n', STD_ERR);
}
