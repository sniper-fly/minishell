#include "validation.h"
#include "struct/t_bool.h"

// リダイレクト後メタ
static t_bool	is_meta_following_redirect(t_bool is_redirect)
{
	if (is_redirect)
		return (TRUE);
	else
		return (FALSE);
}

// メタ後メタ
static t_bool	is_meta_following_meta(char *cmd_line)
{
	if (is_meta_char(*cmd_line))
		return (TRUE);
	else
		return (FALSE);
}

t_bool			is_valid_meta(char **cmd_line, t_bool is_redirect)
{
	if (is_meta_char(**cmd_line))
	{
		if (is_meta_following_redirect(is_redirect))
		{
			put_syntax_error_message("invalid a metacharacter");
			return (FALSE);
		}
		++(*cmd_line);
		skip_space(cmd_line);
		if (is_meta_following_meta(*cmd_line))
		{
			put_syntax_error_message("invalid a metacharacter");
			return (FALSE);
		}
	}
	return (TRUE);
}
