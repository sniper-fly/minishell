/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 23:24:37 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/02 17:28:42 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		c_dst = (char *)dst;
		c_src = (char *)src;
		while (n--)
			*c_dst++ = *c_src++;
	}
	else if (dst > src)
	{
		c_dst = (char *)dst + n - 1;
		c_src = (char *)src + n - 1;
		while (n--)
			*c_dst-- = *c_src--;
	}
	return (dst);
}
