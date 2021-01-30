/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:13:40 by rnakai            #+#    #+#             */
/*   Updated: 2020/10/11 15:48:28 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void*))
{
	t_list	*new_list;
	t_list	*head;

	head = ft_lstnew(func(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_list = ft_lstnew(func(lst->content));
		if (new_list == NULL)
		{
			ft_lstclear(&head, del);
		}
		ft_lstadd_back(&head, new_list);
		lst = lst->next;
	}
	return (head);
}
