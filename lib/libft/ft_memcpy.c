/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:21:05 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:02:55 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			idx;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	idx = 0;
	while (idx < len)
	{
		dst_ptr[idx] = src_ptr[idx];
		idx++;
	}
	return (dst);
}
