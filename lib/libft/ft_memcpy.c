/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:21:05 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/14 17:16:35 by rnakai           ###   ########.fr       */
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

// #include <stdio.h>
// #include <string.h>
// int		main(void)
// {
// 	char *	hoge = NULL;
// 	char *ahoge = NULL;
// 	// printf("%p", memcpy(hoge, ahoge, 0));
// 	// printf("%p", ft_memcpy(hoge, ahoge, 0));
// 	printf("\n");
// 	return (0);
// }
