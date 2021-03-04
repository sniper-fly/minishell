/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 22:09:09 by yyabumot          #+#    #+#             */
/*   Updated: 2020/07/02 14:45:39 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*uc_str;
	unsigned char	uc_c;

	i = 0;
	uc_str = (unsigned char *)str;
	uc_c = (unsigned char)c;
	while (i < n)
	{
		uc_str[i] = uc_c;
		++i;
	}
	return (str);
}
