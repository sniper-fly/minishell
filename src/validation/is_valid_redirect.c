#include "validation.h"
#include "struct/t_bool.h"

// リダイレクト後リダイレクト
static t_bool is_single_redirect(char **cmd_line)
{
	if(**cmd_line == '<')
		++(*cmd_line);
	else if (**cmd_line == '>')
	{
		++(*cmd_line);
		if(**cmd_line == '>')
			++(*cmd_line);
	}
	skip_space(cmd_line);
	if(is_redirect_char(**cmd_line))	// TODO:エラー出力
		return FALSE;
	return TRUE;
}

t_bool is_valid_redirect(char **cmd_line, t_bool *is_redirect)
{
	if(is_redirect_char(**cmd_line))
	{
		*is_redirect = TRUE;
		if(!is_single_redirect(cmd_line))
			return FALSE;
	}
	return TRUE;
}
