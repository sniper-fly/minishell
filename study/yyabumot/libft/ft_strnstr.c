/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 07:20:06 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/06 07:20:14 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hystck, const char *ndl, size_t len)
{
	size_t	i;
	size_t	hystck_len;
	size_t	ndl_len;

	i = 0;
	hystck_len = ft_strlen(hystck);
	ndl_len = ft_strlen(ndl);
	if (ndl_len == 0)
		return ((char *)hystck);
	while (i + ndl_len < len + 1 && i < hystck_len)
	{
		if (hystck[i] == ndl[0])
		{
			if (ft_strncmp(&hystck[i], ndl, ndl_len) == 0)
				return ((char *)&hystck[i]);
		}
		++i;
	}
	return (NULL);
}
