/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:53:25 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:53:25 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "env_ctrl.h"
#include "constants.h"
#include "struct/env_list.h"

extern volatile sig_atomic_t g_status;
extern char *g_pwd;
extern t_env_list *g_env_list;

int	init_pwd(void)
{
	DIR			*tmp;
	t_env_list	*env_pwd;

	if ((env_pwd = search_env_node("PWD")) != g_env_list
	&& (tmp = opendir(env_pwd->value)))
	{
		closedir(tmp);
		if (!(g_pwd = ft_strdup(env_pwd->value)))
		{
			g_status = malloc_error();
			return (ERROR);
		}
	}
	else
		g_pwd = getcwd(NULL, 0);
	return (SUCCESS);
}
