/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 16:30:57 by yyabumot          #+#    #+#             */
/*   Updated: 2020/06/27 10:40:01 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}