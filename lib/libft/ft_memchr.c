/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 15:12:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/06/30 15:35:07 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memchr(const void *str, int ch, size_t len)
{
	size_t			idx;
	unsigned char	search_ch;
	unsigned char	*searched_str;

	searched_str = (unsigned char*)str;
	search_ch = (unsigned char)ch;
	idx = 0;
	while (idx < len)
	{
		if (searched_str[idx] == search_ch)
			return (searched_str + idx);
		idx++;
	}
	return (NULL);
}

/*
**#include <stdio.h>
**#include <string.h>
**
**int		main(void)
**{
**	char str[] = "abc\0Def";
**	char *p1 = memchr(str, 'd', 9);
**	char *p2 = ft_memchr(str, 'd', 9);
**	if (p1 == NULL)
**	{
**		printf("nothing p1");
**		printf("\n");
**	}
**	else
**	{
**		printf("%s", p1);
**		printf("\n");
**	}
**	if (p2 == NULL)
**	{
**		printf("nothing p2");
**		printf("\n");
**	}
**	else
**	{
**		printf("%s", p2);
**		printf("\n");
**	}
**
**	return (0);
**}
*/
