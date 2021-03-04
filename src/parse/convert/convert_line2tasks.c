/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_line2tasks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:52:53 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:52:53 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "libft.h"
#include "struct/process.h"
#include <stdlib.h>
#include "utils.h"
#include "parse.h"

static void		cut_last_endl(char *line)
{
	char	*endl_ptr;

	endl_ptr = ft_strchr(line, '\n');
	if (endl_ptr)
		*endl_ptr = '\0';
}

char			***convert_line2tasks(char *line)
{
	char		**semicolon_splitted;
	char		**pipe_spilitted;
	char		***tasks;
	int			i;

	cut_last_endl(line);
	replace_meta_with_divider(line, ';');
	semicolon_splitted = ft_split(line, DIVIDER);
	tasks = (char***)ft_calloc(sizeof(char**),
		(count_string_arr_row(semicolon_splitted) + 1));
	i = 0;
	while (semicolon_splitted[i])
	{
		replace_meta_with_divider(semicolon_splitted[i], '|');
		pipe_spilitted = ft_split(semicolon_splitted[i], DIVIDER);
		tasks[i] = pipe_spilitted;
		i++;
	}
	free_string_arr(semicolon_splitted);
	return (tasks);
}
