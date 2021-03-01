#ifndef MAIN_H
# define MAIN_H

# include "constants.h"

void	print_prompt(void);
int		p_lack_of_heap_mem_err(void);
t_bool	is_full_of_space(char *line);
t_bool	is_valid_command_line(char *cmd_line);
void		setup_shell(char **line, char **envp);

#endif
