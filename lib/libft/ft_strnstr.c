/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 15:19:04 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/01 16:52:23 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		idx;
	int		l_len;

	l_len = ft_strlen(little);
	if (l_len == 0)
		return ((char*)big);
	idx = 0;
	while (idx < (int)len - l_len + 1 && big[idx] != '\0')
	{
		if (ft_strncmp(&big[idx], little, l_len) == 0)
		{
			return ((char*)(big + idx));
		}
		idx++;
	}
	return (NULL);
}

/*
** #include <stdio.h>
** #include <stddef.h>
** #include <string.h>
** int		main(void)
** {
** 	char big[] = "0123456789";
** 	char small[] = "789";
** 	printf("%s", ft_strnstr(big, "", 10));
** 	printf("\n");
** 	printf("%s", strnstr(big, "", 10));
** 	printf("\n");
** 	printf("\n");
** 	printf("%s", ft_strnstr(small, big, 3));
** 	printf("\n");
** 	printf("%s", strnstr(small, big, 3));
** 	printf("\n");
** 	printf("\n");
** 	printf("%s", ft_strnstr(big, small, 13));
** 	printf("\n");
** 	printf("%s", strnstr(big, small, 13));
** 	printf("\n");
** 	printf("\n");
** 	printf("%s", ft_strnstr(small, big, 9));
** 	printf("\n");
** 	printf("%s", strnstr(small, big, 9));
** 	printf("\n");
** 	printf("\n");
** 	printf("%s", ft_strnstr(big, small, 0));
** 	printf("\n");
** 	printf("%s", strnstr(big, small, 0));
** 	printf("\n");
** 	printf("\n");
** 	return (0);
** }
*/
