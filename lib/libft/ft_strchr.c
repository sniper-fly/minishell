/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:16:46 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/01 14:41:04 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strchr(const char *str, int ch)
{
	size_t	idx;
	char	*result;

	result = (char *)str;
	idx = 0;
	while (1)
	{
		if (str[idx] == (char)ch)
		{
			return (&result[idx]);
		}
		if (str[idx] == '\0')
		{
			return (NULL);
		}
		idx++;
	}
}

/*
** #include <stdio.h>
** #include <string.h>
** int		main(void)
** {
** 	char hoge[] = "abcdefghijk";
** 	printf("%p", ft_strchr(hoge, 'x'));
** 	printf("\n");
** 	printf("%p", strchr(hoge, 'x'));
** 	return (0);
** }
*/
