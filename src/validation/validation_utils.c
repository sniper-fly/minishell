#include <stdlib.h>
#include "validation.h"
#include "struct/t_bool.h"

t_bool is_meta_char(char c)
{
	if(c == '|' || c == ',' || c == ';')
		return TRUE;
	return FALSE;
}

t_bool is_redirect_char(char c)
{
	if(c == '<' || c == '>')
		return TRUE;
	return FALSE;
}

t_bool is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r')
		return TRUE;
	return FALSE;
}
