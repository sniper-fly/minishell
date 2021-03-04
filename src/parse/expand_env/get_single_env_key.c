/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_env_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:37 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 16:45:36 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "parse.h"
#include "struct/t_bool.h"
#include "constants.h"

static t_bool	is_env_end_char(char ch)
{
	if (ft_isalnum(ch) || ch == '_')
		return (FALSE);
	return (TRUE);
}

char			*get_single_env_key(char *str, int idx)
{
	char	*single_envkey;
	int		buf_size;
	int		i;

	if (str[idx] == '?')
		return (ft_strdup("?"));
	buf_size = BUF_LEN;
	single_envkey = ft_calloc(sizeof(char), buf_size);
	i = 0;
	while (!is_env_end_char(str[idx]))
	{
		single_envkey =
			auto_resize_cpy(single_envkey, i, &buf_size, str[idx]);
		idx++;
		i++;
	}
	return (single_envkey);
}
