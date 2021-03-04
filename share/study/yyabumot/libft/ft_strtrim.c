/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:57:49 by yyabumot          #+#    #+#             */
/*   Updated: 2021/01/11 14:09:43 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	src_len;
	char	*src;

	src_len = ft_strlen(s1);
	if (s1 == NULL)
		return (NULL);
	i = src_len;
	while (0 < --i && isset(s1[i], set) == 1)
		--src_len;
	if(isset(s1[i], set) == 1)
		--src_len;
	i = 0;
	if (src_len > 0)
	{
		while (s1[i] != '\0' && isset(s1[i], set) == 1)
		{
			++i;
			--src_len;
		}
	}
	if (!(src = (char *)malloc(sizeof(char) * (src_len + 1))))
		return (NULL);
	ft_strlcpy(src, &s1[i], src_len + 1);
	return (src);
}
