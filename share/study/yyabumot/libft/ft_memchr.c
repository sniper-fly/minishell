/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 08:30:54 by yyabumot          #+#    #+#             */
/*   Updated: 2021/01/11 11:23:53 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_str;
	unsigned char	uc_c;

	i = 0;
	uc_str = (unsigned char *)str;
	uc_c = (unsigned char)c;
	while (i < n)
	{
		if (uc_str[i] == uc_c)
			return ((void *)&uc_str[i]);
		++i;
	}
	return (0);
}
