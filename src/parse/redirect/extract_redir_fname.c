#include "struct/redir_mode.h"
#include "libft.h"
#include "parse.h"
#include <stdlib.h>

static void	free_three(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
}

char		*extract_redir_fname(t_redir_mode *current_redir, char *raw_redir_fname)
{
	char			*redir_expanded;
	char			*redir_trimmed;
	char			*redir_filename;

	redir_expanded = expand_env_var_str(raw_redir_fname);
	redir_trimmed = ft_strtrim(redir_expanded, " \t\n\v\f\r");
	if (is_ambiguous_err(redir_trimmed))
	{
		free_three(redir_expanded, redir_trimmed, current_redir->fd_str);
		p_ambiguous_err(raw_redir_fname);
		return (NULL);
	}
	redir_filename = cut_modifier(redir_trimmed);
	free_three(redir_expanded, redir_trimmed, NULL);
	return (redir_filename);
}
