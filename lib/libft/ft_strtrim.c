/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 17:42:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 11:39:05 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int	ft_is_in_set(char searched_ch, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx])
	{
		if (searched_ch == set[idx])
			return (1);
		idx++;
	}
	return (0);
}

/*
** if strlen(s1) is "", idx must not be minus, that is why line 47 is necessary.
*/

char		*ft_strtrim(char const *s1, char const *set)
{
	int		idx;
	int		start;
	int		end;
	char	*ptr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	idx = 0;
	while (ft_is_in_set(s1[idx], set) == 1)
		idx++;
	start = idx;
	idx = (ft_strlen(s1)) ? ft_strlen(s1) - 1 : 0;
	while (ft_is_in_set(s1[idx], set) == 1)
		idx--;
	end = idx;
	if (start > end)
		return ((char *)ft_calloc(1, sizeof(char)));
	if (!(ptr = (char *)ft_calloc(end - start + 2, sizeof(char))))
		return (NULL);
	idx = 0;
	while (start <= end)
		ptr[idx++] = s1[start++];
	return (ptr);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	printf("01234 : %s", ft_strtrim("str0str", "str"));
** 	printf("\n");
** 	printf("01234 : %s", ft_strtrim("01234str", "str"));
** 	printf("\n");
** 	printf("01234 : %s", ft_strtrim("str01234", "str"));
** 	printf("\n");
** 	printf("012str34 : %s", ft_strtrim("str012str34str", "str"));
** 	printf("\n");
** 	printf("01234 : %s", ft_strtrim("01234", "str"));
** 	printf("\n");
** 	printf("012345 : %s", ft_strtrim("strstr012345strstr", "str"));
** 	printf("\n");
** 	printf("str01234str : %s", ft_strtrim("str01234str", ""));
** 	printf("\n");
** 	printf("str01234str : %s", ft_strtrim("str01234str", "k"));
** 	printf("\n");
** 	printf("01234ttttt : %s", ft_strtrim("sssss01234tttttr", "rs"));
** 	printf("\n");
** 	printf("%s", ft_strtrim("strstr", "str"));
** 	printf("\n");
** 	printf("%s", ft_strtrim("", "str"));
** 	printf("\n");
** 	printf("%s", ft_strtrim(NULL, "str"));
** 	printf("\n");
** 	printf("%s", ft_strtrim("str", NULL));
** 	printf("\n");
** 	printf("%s", ft_strtrim(NULL, NULL));
** 	return (0);
** }
*/
