/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_redir_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:19 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:51:19 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct/process.h"
#include "struct/redir_mode.h"
#include "struct/t_bool.h"
#include "parse.h"
#include "libft.h"
#include "utils.h"

static void		init_redir_mode(t_redir_mode *redir_mode)
{
	redir_mode->mode_bit = 0;
	redir_mode->fd_str = NULL;
}

static void		set_redir_fd_str(
	char *str_proc, int i, t_redir_mode *redir_mode)
{
	int		fd_len;

	fd_len = 0;
	i--;
	while (i >= 0 && ft_isdigit(str_proc[i]) == TRUE)
	{
		fd_len++;
		i--;
	}
	if (i < 0)
	{
		if (ft_isdigit(str_proc[0]))
			redir_mode->fd_str = ft_substr(str_proc, 0, fd_len);
		return ;
	}
	if (ft_isspace(str_proc[i]) && ft_isdigit(str_proc[i + 1]))
		redir_mode->fd_str = ft_substr(str_proc, i + 1, fd_len);
}

static t_bool	is_fd_str_valid(char *fd_str)
{
	if (fd_str == NULL)
		return (TRUE);
	if (ft_strlen(fd_str) > 1)
		return (FALSE);
	if (fd_str[0] == '0' || fd_str[0] == '1' || fd_str[0] == '2')
		return (TRUE);
	return (FALSE);
}

static t_bool	is_fd_pair_valid(t_redir_mode *redir_mode)
{
	if (redir_mode->fd_str == NULL)
		return (TRUE);
	if ((redir_mode->mode_bit & REDIR_IN) && redir_mode->fd_str[0] != '0')
		return (FALSE);
	else if ((redir_mode->mode_bit & REDIR_OUT) && redir_mode->fd_str[0] == '0')
		return (FALSE);
	return (TRUE);
}

void			detect_redir_mode(
	char *str_proc, int i, t_redir_mode *redir_mode)
{
	init_redir_mode(redir_mode);
	set_redir_fd_str(str_proc, i, redir_mode);
	if (!is_fd_str_valid(redir_mode->fd_str))
	{
		redir_mode->mode_bit = REDIR_BAD_FD;
		return ;
	}
	if (str_proc[i] == '<')
		redir_mode->mode_bit = REDIR_IN;
	else
	{
		if (redir_mode->fd_str != NULL && redir_mode->fd_str[0] == '2')
			redir_mode->mode_bit = REDIR_ERR;
		else
			redir_mode->mode_bit = REDIR_OUT;
		if (str_proc[i + 1] == '>')
			redir_mode->mode_bit |= REDIR_APPEND;
	}
	if (!is_fd_pair_valid(redir_mode))
		redir_mode->mode_bit = REDIR_BAD_FD;
}
