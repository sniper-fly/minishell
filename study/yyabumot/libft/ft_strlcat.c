/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 11:32:49 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/05 21:44:33 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t s_len;
	size_t d_len;

	i = 0;
	s_len = ft_strlen(src);
	d_len = ft_strlen(dst);
	if (dstsize == 0 || d_len > dstsize)
		return (s_len + dstsize);
	while (d_len + i < dstsize - 1 && src[i] != '\0')
	{
		dst[d_len + i] = src[i];
		++i;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
