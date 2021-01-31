/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:58:13 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/11 11:46:51 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char		*ft_strrchr(const char *str, int ch)
{
	size_t	idx;
	size_t	last;
	char	*result;
	int		flag;

	result = (char *)str;
	idx = 0;
	flag = 0;
	while (1)
	{
		if (str[idx] == (char)ch)
		{
			flag = 1;
			last = idx;
		}
		if (str[idx] == '\0')
			break ;
		idx++;
	}
	if (flag == 0)
		return (NULL);
	return (&result[last]);
}

/*
** #include <stdio.h>
** #include <string.h>
** int		main(void)
** {
** 	char hoge[] = "\0abc1abc2abc3bbc4 j\0abc5abc6abc7";
** 	printf("%s", ft_strrchr(hoge, '\0'));
** 	printf("\n");
** 	printf("%s", strrchr(hoge, '\0'));
** 	return (0);
** }
*/
