#include "struct/process.h"
#include "libft.h"
#include <stdlib.h>
#include "parse.h"
#include "constants.h"
#include "exit_status.h"
#include "struct/redir_mode.h"

static void	free_redir(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
}

static void	set_redir_config(t_process *proc, t_process *redir_config)
{
	proc->red_in_file_name = redir_config->red_in_file_name;
	proc->red_err_file_name = redir_config->red_err_file_name;
	proc->red_out_file_name = redir_config->red_out_file_name;
	proc->red_out_mode = redir_config->red_out_mode;
	proc->red_err_mode = redir_config->red_err_mode;
}

static int	interpret_as_redir(char *str_proc, int i, t_process *redir_config)
{
	char			*raw_redir_file;
	char			*redir_expanded;
	char			*redir_filename;
	t_redir_mode	current_redir;
	int				strlen_has_read;

	detect_redir_mode(str_proc, i, &current_redir);
	if (current_redir.mode_bit & REDIR_BAD_FD)
	{
		return (p_bad_fd_err(current_redir.fd_str));
	}
	raw_redir_file = get_redirect_file(str_proc, i, current_redir.mode_bit); //TODO:
	redir_expanded = expand_env_var_str(raw_redir_file);
	if (is_ambiguous_err(redir_expanded))
	{
		return (p_ambiguous_err(
			current_redir.fd_str, raw_redir_file, redir_expanded));
	}
	redir_filename = cut_modifier(redir_expanded);
	update_redir_config(redir_config, redir_filename, &current_redir);
	if (open_redir_file(redir_filename, redir_config, &current_redir) == ERROR)
	{
		return (p_open_err(current_redir.fd_str,
			raw_redir_file, redir_expanded, redir_config));
	}
	strlen_has_read =
		count_redir_len(str_proc, i, current_redir.mode_bit, raw_redir_file);
	fill_space(str_proc, i, &current_redir, raw_redir_file);
	free_redir(raw_redir_file, redir_expanded, current_redir.fd_str);
	return (strlen_has_read);
}

int			parse_redirect(char *str_proc, t_process *proc)
{
	t_process	redir_config;
	int			i;
	int			strlen_has_read;

	ft_bzero(&redir_config, sizeof(t_process));
	i = 0;
	while (str_proc[i])
	{
		if (is_escape(str_proc[i]))
		{
			skip_escape_seq(str_proc, &i);
			continue ;
		}
		if (str_proc[i] == '<' || str_proc[i] == '>')
		{
			strlen_has_read = interpret_as_redir(str_proc, i, &redir_config);
			if (strlen_has_read == ERROR)
				return (ERROR);
			i += strlen_has_read;
			continue ;
		}
		i++;
	}
	set_redir_config(proc, &redir_config);
	return (SUCCESS);
}
