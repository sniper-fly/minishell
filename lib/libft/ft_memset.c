/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:49:19 by rnakai            #+#    #+#             */
/*   Updated: 2020/06/29 18:20:45 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	size_t			idx;
	void			*result;

	result = buf;
	ptr = (unsigned char *)buf;
	ch = (unsigned char)ch;
	idx = 0;
	while (idx < n)
	{
		ptr[idx] = ch;
		idx++;
	}
	return (result);
}
