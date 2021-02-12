#ifndef VALIDATION_H
#define VALIDATION_H

#include "struct/t_bool.h"

void put_syntax_error_message(char *msg);
t_bool is_meta_char(char c);
t_bool is_redirect_char(char c);
t_bool is_space(char c);
t_bool is_valid_char_code(char *cmd_line);

t_bool is_valid_meta_and_redirect(char *cmd_line);

#endif
