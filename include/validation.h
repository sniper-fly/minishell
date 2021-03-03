#ifndef VALIDATION_H
#define VALIDATION_H

#include "struct/t_bool.h"

void	put_syntax_error_message(char *msg);
t_bool	is_meta_char(char c);
t_bool	is_redirect_char(char c);
void	skip_space(char **cmd_line);
t_bool	is_valid_char_code(char *cmd_line);
t_bool	is_valid_meta(char **cmd_line, t_bool is_redirect);
t_bool	is_valid_redirect(char **cmd_line, t_bool *is_redirect);
t_bool	is_valid_meta_and_redirect(char *cmd_line);
t_bool is_valid_quote(char *cmd_line);
t_bool is_valid_command_line(char *cmd_line);
t_bool	is_cmd_line_terminated_with_bkslsh(char *cmd_line);

#endif
