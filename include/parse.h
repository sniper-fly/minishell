#ifndef PARSE_H
# define PARSE_H

# include "struct/process.h"
# include "struct/t_bool.h"
# include "struct/redir_mode.h"

# define DIVIDER -3

#ifndef DEBUG  //後で削除。デバッグ用で値をいじれるように
# define RESIZE_BUF_LEN 1000 
#endif

# define BUF_LEN 1000

char		***convert_line2tasks(char *line);
void		replace_meta_with_divider(char *line, char rplced_ch);

void		free_tasks(char ***tasks);

t_process	*parse_each_task(char **str_procs);

void		parse_redirect_and_fill_space(char *str_proc, t_process *proc);

char		*expand_env_var_str(char *str);
char		*auto_resize_cpy(char *dst, int idx, int *buf_size, char src_ch);
char		*get_single_env_key(char *str, int idx);
char		*join_env_value(char *expanded_str, int *buflen, char *env_key);
char		*auto_resize_join(char *dst, int *buflen, char ch);

char		*handle_escape( char *expanded_str, int *buflen, char *str, int *i);

char		*interpret_envvar( char *expanded_str, int *buflen, char *str, int *i);
t_bool		should_interpret_as_envvar(char *str, int i);

void		detect_redir_mode(char *str_proc, int i, t_redir_mode *redir_mode);
char		*get_redirect_file(char *str, int i, int mode_bit);

void		skip_space_idx(char *str, int *i);
void		skip_until_end_single_quote(char *line, int *idx);
void		skip_until_end_double_quote(char *line, int *idx);

#endif
