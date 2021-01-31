/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 10:48:47 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 12:42:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *listptr;
	t_list *next_list;

	listptr = *lst;
	while (listptr != NULL)
	{
		next_list = listptr->next;
		ft_lstdelone(listptr, del);
		listptr = next_list;
	}
	*lst = NULL;
}
