/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:57:43 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:57:45 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "struct/env_list.h"
#include <signal.h>

extern volatile sig_atomic_t			g_status;
extern t_env_list	*g_env_list;

char	**get_path_array(void)
{
	char		**path;
	t_env_list	*nil;
	t_env_list	*tmp;

	nil = g_env_list;
	tmp = g_env_list->next;
	while (tmp != nil)
	{
		if (!ft_strcmp(tmp->key, "PATH"))
			break ;
		tmp = tmp->next;
	}
	if (tmp == g_env_list)
		return (NULL);
	if (!(path = ft_split(tmp->value, ':')))
		exit(malloc_error());
	return (path);
}
