#include <stdlib.h>
#include "validation.h"
#include "struct/t_bool.h"

static void skip_space(char **cmd_line)
{
	while(is_space(**cmd_line))
		++(*cmd_line);
}

static void skip_normal_char(char **cmd_line)
{
	while(**cmd_line){
		if(is_meta_char(**cmd_line) || is_redirect_char(**cmd_line))
			break;
		++(*cmd_line);
	}
}

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
	// リダイレクト後リダイレクト
	if(is_redirect_char(**cmd_line))	// TODO:エラー出力
		return FALSE;
	return TRUE;
}

static t_bool is_valid_meta(char **cmd_line, int redirect_flag)
{
	// リダイレクト後メタ
	if(redirect_flag)	// TODO:エラー出力
		return FALSE;
	++(*cmd_line);
	skip_space(cmd_line);
	// メタ後メタ
	if(is_meta_char(**cmd_line))	// TODO:エラー出力
		return FALSE;
	return TRUE;
}

t_bool is_valid_meta_and_redirect(char *cmd_line)
{
	int redirect_flag;

	skip_space(&cmd_line);
	// 初手メタ
	if(is_meta_char(*cmd_line) == TRUE)
		return FALSE;
	while(*cmd_line)
	{
		redirect_flag = 0;
		// 関係ない文字をスキップ
		skip_normal_char(&cmd_line);
		if(is_redirect_char(*cmd_line))
		{
			redirect_flag = 1;
			if(!is_single_redirect(&cmd_line))
				return FALSE;
		}
		if(is_meta_char(*cmd_line))
		{
			if(!is_valid_meta(&cmd_line, redirect_flag))
				return FALSE;
		}
		skip_space(&cmd_line);
		// 最後リダイレクト
		if(redirect_flag && !(*cmd_line))
			return FALSE;
	}
	return TRUE;
}
