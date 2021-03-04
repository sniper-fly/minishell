/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_procs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:08 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:09 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "struct/process.h"

int	count_procs(t_process *procs)
{
	int	count;

	count = 0;
	while (procs[count].is_end != TRUE)
		++count;
	return (count);
}
