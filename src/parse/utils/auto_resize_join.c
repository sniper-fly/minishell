/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_resize_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:49:14 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:49:15 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"

/*
** dstの末尾にchを一文字追加する
*/

char		*auto_resize_join(char *dst, int *buflen, char ch)
{
	int		dst_len;

	dst_len = ft_strlen(dst);
	dst = auto_resize_cpy(dst, dst_len, buflen, ch);
	return (dst);
}
