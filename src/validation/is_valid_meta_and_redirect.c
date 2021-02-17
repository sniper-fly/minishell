#include <stdlib.h>
#include "validation.h"
#include "struct/t_bool.h"

// 関係ない文字をスキップ
static void		skip_normal_char(char **cmd_line)
{
	while (**cmd_line)
	{
		if (is_meta_char(**cmd_line) || is_redirect_char(**cmd_line))
			break;
		++(*cmd_line);
	}
}

// 初手メタ
static t_bool	is_started_with_meta(char *cmd_line)
{
	if (is_meta_char(*cmd_line))
	{
		put_syntax_error_message("invalid token");
		return (TRUE);
	}
	else
		return (FALSE);
}


// 最後リダイレクト
static t_bool	is_terminated_with_redirect(char *cmd_line, t_bool is_redicrect)
{
	if (is_redicrect && !(*cmd_line))	// TODO: エラー出力
	{
		put_syntax_error_message("invalid redirect");
		return (TRUE);
	}
	return (FALSE);
}

t_bool			is_valid_meta_and_redirect(char *cmd_line)
{
	t_bool	is_redirect;

	skip_space(&cmd_line);
	if (is_started_with_meta(cmd_line))
		return (FALSE);
	while (*cmd_line)
	{
		is_redirect = FALSE;
		skip_normal_char(&cmd_line);
		if (!is_valid_redirect(&cmd_line, &is_redirect))
			return (FALSE);
		if (!is_valid_meta(&cmd_line, is_redirect))
			return (FALSE);
		skip_space(&cmd_line);
		if (is_terminated_with_redirect(cmd_line, is_redirect))
			return (FALSE);
	}
	return (TRUE);
}
