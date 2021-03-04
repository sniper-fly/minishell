/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:51:46 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:51:47 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "struct/env_list.h"

static int	count_bk_slsh_should_insert(char *value)
{
	int	bk_slsh_count;

	bk_slsh_count = 0;
	while (*value)
	{
		if (*value == '\\' || *value == '$' || *value == '\"')
			++bk_slsh_count;
		++value;
	}
	return (bk_slsh_count);
}

static char	*insert_back_slash(char *value)
{
	int		i;
	char	*value_inserted_bk_slsh;

	if (!(value_inserted_bk_slsh =
	malloc(sizeof(char) *
	(ft_strlen(value) + count_bk_slsh_should_insert(value) + 1))))
		exit(malloc_error());
	i = 0;
	while (*value)
	{
		if (*value == '\\' || *value == '$' || *value == '\"')
		{
			value_inserted_bk_slsh[i] = '\\';
			++i;
		}
		value_inserted_bk_slsh[i] = *value;
		++i;
		++value;
	}
	value_inserted_bk_slsh[i] = '\0';
	return (value_inserted_bk_slsh);
}

static char	*create_tmp_env_str(char *env_str, t_env_list *env_node)
{
	char	*tmp;
	char	*value_inserted_bk_slsh;

	if (ft_strchr(env_node->value, '\\') || ft_strchr(env_node->value, '$')
	|| ft_strchr(env_node->value, '\"'))
	{
		value_inserted_bk_slsh = insert_back_slash(env_node->value);
		if (!(tmp = ft_strjoin(env_str, value_inserted_bk_slsh)))
			exit(malloc_error());
		free(value_inserted_bk_slsh);
	}
	else
	{
		if (!(tmp = ft_strjoin(env_str, env_node->value)))
			exit(malloc_error());
	}
	return (tmp);
}

char		*create_env_str(t_env_list *env_node)
{
	char	*env_str;
	char	*tmp;

	if (!(env_node->value))
	{
		if (!(env_str = ft_strdup(env_node->key)))
			exit(malloc_error());
	}
	else
	{
		if (!(env_str = ft_strjoin(env_node->key, "=\"")))
			exit(malloc_error());
		tmp = create_tmp_env_str(env_str, env_node);
		free(env_str);
		if (!(env_str = ft_strjoin(tmp, "\"")))
			exit(malloc_error());
		free(tmp);
	}
	return (env_str);
}
