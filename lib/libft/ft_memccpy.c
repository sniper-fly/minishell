/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 12:22:09 by rnakai            #+#    #+#             */
/*   Updated: 2020/06/30 14:11:28 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memccpy(void *dst, const void *src, int ch, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	size_t			idx;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	idx = 0;
	while (idx < len)
	{
		dst_ptr[idx] = src_ptr[idx];
		if (src_ptr[idx] == (unsigned char)ch)
			return (dst_ptr + idx + 1);
		idx++;
	}
	return (NULL);
}
