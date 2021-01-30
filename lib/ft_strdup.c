/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:47:07 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/02 17:55:16 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	strsize;

	strsize = ft_strlen(str);
	ptr = (char *)malloc((strsize + 1) * sizeof(char));
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(ptr, str, strsize + 1);
	return (ptr);
}
