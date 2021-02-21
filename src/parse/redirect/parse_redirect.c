#include "struct/process.h"
#include "libft.h"
#include <stdlib.h>
#include "parse.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/redir_mode.h"

#ifndef DEBUG ///////////////////////////////////NOTE: 消す

static int	interpret_as_redir(
	char *str_proc, int i, t_process *proc, t_process *redir_config)
{
	char		*raw_redir_file;
	char		*redir_expanded;
	char		*redir_filename;
	t_redir_mode	redir_mode;
	int			strlen_has_read;

	detect_redir_mode(str_proc, i, &redir_mode);
	if (is_bad_fd(&redir_mode))
	{
		return (p_bad_fd_err(&redir_mode));
	}
	skip_space(str_proc, &i);
	raw_redir_file = get_redirect_file(str_proc, i);
	fill_space(str_proc, i, redir_mode, raw_redir_file);
	redir_expanded = expand_env_var_str(raw_redir_file);
	if (is_ambigous_error(redir_expanded))
	{
		return (p_redir_err(raw_redir_file, redir_expanded));
	}
	redir_filename = cut_modifier(redir_expanded);
	if (!can_open(redir_filename, &redir_mode))
	{
		return (p_open_err(raw_redir_file, redir_expanded, redir_filename));
	}
	update_redir_config(&redir_config, redir_filename);
	strlen_has_read = count_redir_len(str_proc, i, redir_mode.fd_str);
	free_redir(raw_redir_file, redir_expanded, redir_mode.fd_str);
	return (strlen_has_read);
}

void		parse_redirect(char *str_proc, t_process *proc)
{
	t_process	redir_config;
	int			i;
	int			strlen_has_read;

	init_redir_config(&redir_config);
	i = 0;
	while (str_proc[i])
	{
		if (str_proc[i] == '<' || str_proc[i] == '>')
		{
			strlen_has_read =
				interpret_as_redir(str_proc, i, proc, &redir_config);
			if (strlen_has_read == ERROR)
				return (GENERAL_ERRORS);
			i += strlen_has_read;
			continue ;
		}
		i++;
	}
	set_redir_config(proc, &redir_config);
}

#endif
