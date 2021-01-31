/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:36:49 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/11 12:43:20 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len_total;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_total = len_s1 + len_s2 + 1;
	ptr = (char *)ft_calloc(len_total, sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len_s1 + 1);
	ft_strlcat(ptr, s2, len_total);
	return (ptr);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	char hoge[] = "";
** 	char ahoge[] = "aa";
** 	printf("%s", ft_strjoin(NULL, NULL));
** 	return (0);
** }
*/
