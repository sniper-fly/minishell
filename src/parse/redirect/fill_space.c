/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:26 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:51:27 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct/redir_mode.h"
#include "libft.h"
#include "parse.h"
#include "utils.h"

void		fill_space(
	char *str_proc, int i, t_redir_mode *current_redir, char *raw_redir)
{
	int		times;

	times = 0;
	if (current_redir->fd_str)
	{
		i -= 1;
		times++;
	}
	times += (current_redir->mode_bit & REDIR_APPEND) ? 2 : 1;
	while (times > 0)
	{
		str_proc[i] = ' ';
		i++;
		times--;
	}
	skip_space_idx(str_proc, &i);
	times = ft_strlen(raw_redir);
	while (times > 0)
	{
		str_proc[i] = ' ';
		i++;
		times--;
	}
}
