/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 08:38:09 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/02 15:52:13 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	int				d;
	unsigned char	*uc_str1;
	unsigned char	*uc_str2;

	i = 0;
	uc_str1 = (unsigned char *)str1;
	uc_str2 = (unsigned char *)str2;
	while (i < n)
	{
		d = uc_str1[i] - uc_str2[i];
		if (d != 0)
			return (d);
		++i;
	}
	return (0);
}
