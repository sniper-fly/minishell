/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:41:40 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/07 12:23:54 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int idx;

	if (dstsize == 0)
		return (ft_strlen(src));
	idx = 0;
	while (!(idx >= dstsize - 1 || src[idx] == '\0'))
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = '\0';
	return (ft_strlen(src));
}
