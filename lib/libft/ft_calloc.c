/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:11:35 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/03 12:35:09 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int	memalloc_error(void)
{
	ft_putendl_fd("minishell: malloc error", 2);
	return (2);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
	{
		exit(memalloc_error());
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
