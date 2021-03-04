/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_cmd_to_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:04:29 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 15:04:30 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"

char	*join_cmd_to_path(char *cmd, char *path_ptr)
{
	char	*add_slash;
	char	*cmd_path;

	add_slash = NULL;
	if (path_ptr[ft_strlen(path_ptr) - 1] != '/')
	{
		if (!(add_slash = ft_strjoin(path_ptr, "/")))
			exit(malloc_error());
		if (!(cmd_path = ft_strjoin(add_slash, cmd)))
			exit(malloc_error());
	}
	else
	{
		if (!(cmd_path = ft_strjoin(path_ptr, cmd)))
			exit(malloc_error());
	}
	free(add_slash);
	return (cmd_path);
}
