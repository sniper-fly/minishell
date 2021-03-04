/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:46:59 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:47:00 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "struct/t_bool.h"

typedef struct	s_process
{
	char		**cmd;
	char		*red_in_file_name;
	char		*red_out_file_name;
	char		*red_err_file_name;
	int			red_out_mode;
	int			red_err_mode;
	t_bool		is_end;
}				t_process;

#endif
