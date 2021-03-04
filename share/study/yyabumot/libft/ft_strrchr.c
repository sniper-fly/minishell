/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 21:58:48 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/05 17:18:29 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		flag;
	char	c_c;

	i = 0;
	flag = -1;
	c_c = (char)c;
	if (c_c == '\0')
		return ((char *)(&s[ft_strlen(s)]));
	while (s[i] != '\0')
	{
		if (s[i] == c_c)
			flag = i;
		++i;
	}
	if (flag == -1)
		return (0);
	return ((char *)(&s[flag]));
}
