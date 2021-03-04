/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_procs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:34 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:51:34 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"
#include "constants.h"
#include "struct/process.h"

void		free_procs(t_process *procs)
{
	int		i;

	i = 0;
	while (procs[i].is_end != TRUE)
	{
		free_string_arr(procs[i].cmd);
		free(procs[i].red_in_file_name);
		free(procs[i].red_out_file_name);
		free(procs[i].red_err_file_name);
		i++;
	}
	free(procs);
}

void		free_single_proc(t_process *proc)
{
	free_string_arr(proc->cmd);
	free(proc->red_in_file_name);
	free(proc->red_out_file_name);
	free(proc->red_err_file_name);
}
