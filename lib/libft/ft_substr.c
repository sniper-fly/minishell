/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 12:48:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/11 12:44:45 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	idx;
	size_t	s_size;

	if (s == NULL)
		return (NULL);
	s_size = ft_strlen(s);
	if (len == 0 || s_size <= start || s_size == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (s_size < len + start)
		len = s_size - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		ptr[idx] = s[start + idx];
		idx++;
	}
	ptr[idx] = '\0';
	return (ptr);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	char hoge[] = "0123456";
** 	printf("3456: %s", ft_substr(hoge, 3, 4));
** 	printf("\n");
** 	printf("01234: %s", ft_substr(hoge, 0, 5));
** 	printf("\n");
** 	printf("none: %s", ft_substr(hoge, 9, 4));
** 	printf("\n");
** 	printf("6: %s", ft_substr(hoge, 6, 10));
** 	printf("\n");
** 	printf("none:%s:%s:", ft_substr("", 5, 0), ""+5);
** 	printf("\n");
** 	printf("none: %s", ft_substr(hoge, 0, 0));
** 	printf("\n");
** 	printf("%s", ft_substr(NULL, 3, 0));
** 	printf("\n");
** 	return (0);
** }
*/
