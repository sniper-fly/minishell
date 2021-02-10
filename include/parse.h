#ifndef PARSE_H
# define PARSE_H

# include "struct/process.h"

# define DIVIDER -3

char		***convert_line2str_procs(char *line);
void		replace_meta_with_divider(char *line, char rplced_ch);
void		free_str_procs(char ***str_procs);

#endif
