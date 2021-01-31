/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:04:06 by rnakai            #+#    #+#             */
/*   Updated: 2020/07/12 12:40:25 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
** #include <stdio.h>
** int		main(void)
** {
** 	t_list *one;
** 	t_list *two;
** 	t_list *three;
** 	t_list *four;
** 	t_list *last;
** 	one = ft_lstnew("one");
** 	two = ft_lstnew("two");
** 	three = ft_lstnew("three");
** 	four = ft_lstnew("four");
** 	ft_lstadd_back(&one, two);
** 	ft_lstadd_back(&one, three);
** 	ft_lstadd_back(&one, four);
** 	last = ft_lstlast(one);
** 	printf("lst size =%d", ft_lstsize(one));
** 	printf("\n");
** 	printf("last is %s", (char *)(last->content));
** 	return (0);
** }
*/
