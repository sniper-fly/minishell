/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:57:24 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:57:35 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct/env_list.h"

void	free_env_node(t_env_list *env_node)
{
	free(env_node->key);
	free(env_node->value);
	free(env_node);
}
