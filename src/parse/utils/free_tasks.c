/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tasks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:49:24 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:49:25 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void		free_tasks(char ***tasks)
{
	int		i;

	i = 0;
	while (tasks[i])
	{
		free_string_arr(tasks[i]);
		i++;
	}
	free(tasks);
}
