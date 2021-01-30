/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 14:13:03 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/14 13:12:16 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;
	int				idx;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		idx = len - 1;
		while (idx >= 0)
		{
			dst_ptr[idx] = src_ptr[idx];
			idx--;
		}
	}
	return (dst);
}

/*
** #include <stdio.h>
** #include <string.h>
** int		main(void)
** {
** 	// char src[] = "0123456";
** 	// char hoge[10];
** 	// printf("%s", (char *)ft_memmove(&src[3], (void*)0, 4));
** 	// printf("\n");
** 	// printf("%s", src);
** 	char *nullsrc = NULL;
** 	char *nullsrc1 = NULL;
** 	printf("%p", memmove(nullsrc1, nullsrc, 0));
** 	printf("\n");
** 	printf("%p", ft_memmove(nullsrc1, nullsrc, 0));
** 	printf("\n");
** }
*/
