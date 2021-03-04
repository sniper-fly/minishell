/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnakai <rnakai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:50:43 by rnakai            #+#    #+#             */
/*   Updated: 2021/03/04 14:50:46 by rnakai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "constants.h"
#include "exit_status.h"

int	malloc_error(void)
{
	ft_putendl_fd("minishell: malloc error", STD_ERR);
	return (GENERAL_ERRORS);
}
