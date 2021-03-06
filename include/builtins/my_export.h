/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyabumot <yyabumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:46:50 by yyabumot          #+#    #+#             */
/*   Updated: 2021/03/04 14:46:51 by yyabumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_EXPORT_H
# define MY_EXPORT_H

# include "struct/env_list.h"

void		sort_keys_by_lexical_order(char **env_str_arr);
char		*create_env_str(t_env_list *env_node);
int			print_env_at_my_export(void);
t_env_list	**create_new_env_nodes_arr(char **args, int *exit_status);
void		add_new_env_var_to_list(t_env_list *new_env_node);
int			my_export(char **args);

#endif
