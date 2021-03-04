/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:25 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:25 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "struct/t_bool.h"

extern const char *g_builtin_func_names[];

t_bool	is_builtin_func(char *cmd)
{
	int	i;
	int	sum_builtins;

	i = 0;
	sum_builtins = count_string_arr_row((char**)g_builtin_func_names);
	while (i < sum_builtins)
	{
		if (!ft_strcmp((char *)g_builtin_func_names[i], cmd))
			return (TRUE);
		++i;
	}
	return (FALSE);
}
