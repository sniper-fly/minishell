/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 21:41:06 by yyabumot          #+#    #+#             */
/*   Updated: 2020/06/29 15:20:25 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *new_elem;
	t_list *old_elem;

	new_elem = ft_lstnew(f(lst->content));
	old_elem = lst->next;
	new_lst = new_elem;
	while (old_elem != NULL)
	{
		if (!(new_elem->next = ft_lstnew(f(old_elem->content))))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_elem = new_elem->next;
		old_elem = old_elem->next;
	}
	return (new_lst);
}
