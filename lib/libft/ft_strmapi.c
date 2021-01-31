/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 14:46:58 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/11 12:43:36 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *str, char (*func)(unsigned int, char))
{
	unsigned int	strlen;
	unsigned int	idx;
	char			*result_str;

	strlen = ft_strlen(str);
	idx = 0;
	if (!(result_str = (char *)ft_calloc(strlen + 1, sizeof(char))))
		return (NULL);
	while (idx < strlen)
	{
		result_str[idx] = func(idx, str[idx]);
		idx++;
	}
	result_str[idx] = '\0';
	return (result_str);
}

/*
** static char test_plusone(unsigned int idx, char ch)
** {
** 	(void)idx;
** 	ch++;
** 	return (ch);
** }
** #include <stdio.h>
** int		main(void)
** {
** 	printf("%s", ft_strmapi("012345", test_plusone));
** 	return (0);
** }
*/
