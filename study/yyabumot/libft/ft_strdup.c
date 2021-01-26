/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:58:35 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/02 16:50:08 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	src_len;
	char	*dst;

	src_len = ft_strlen(src);
	if (!(dst = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	ft_strlcpy(dst, src, src_len + 1);
	return (dst);
}
