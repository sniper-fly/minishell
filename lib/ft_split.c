/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 17:36:30 by yyabumot          #+#    #+#             */
/*   Updated: 2021/01/30 11:50:51 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*conv_null(char const *s, char c)
{
	size_t	i;
	size_t	s_len;
	char	*dst;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(dst = ft_strdup(s)))
		return (NULL);
	while (i < s_len)
	{
		if (dst[i] == c)
			dst[i] = '\0';
		++i;
	}
	return (dst);
}

static size_t	count_strs(char *conved, size_t s_len)
{
	size_t	i;
	int		count;

	i = 1;
	count = 0;
	if (conved == NULL)
		return (0);
	while (i < s_len)
	{
		if (conved[i - 1] != '\0' && conved[i] == '\0')
			++count;
		++i;
	}
	return (count);
}

static void		ft_free(size_t i, char *conved, char **splitted)
{
	while (0 < i)
	{
		free(splitted[i]);
		--i;
	}
	free(splitted[0]);
	free(conved);
	free(splitted);
}

static int		do_split(char **splitted, char *conved, size_t s_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < s_len)
	{
		while (conved[i] == '\0' && i < s_len)
			++i;
		if (i == s_len)
			break ;
		if (!(splitted[j] = ft_strdup(&conved[i])))
		{
			ft_free(j, conved, splitted);
			return (0);
		}
		while (conved[i] != '\0')
			++i;
		++j;
	}
	splitted[j] = NULL;
	return (1);
}

char			**ft_split(char const *s, char c)
{
	size_t	strs;
	size_t	s_len;
	char	*conved;
	char	**splitted;

	s_len = ft_strlen(s);
	if (!(conved = conv_null(s, c)))
		return (NULL);
	strs = count_strs(conved, s_len + 1);
	if (!(splitted = (char **)malloc(sizeof(char *) * (strs + 1))))
		return (NULL);
	if (do_split(splitted, conved, s_len + 1) == 0)
		return (NULL);
	free(conved);
	return (splitted);
}
