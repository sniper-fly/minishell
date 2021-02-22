#include "utils.h"
#include "constants.h"

void		skip_space_idx(char *str, int *i)
{
	while (ft_isspace(str[*i]))
	{
		(*i)++;
	}
}

void		skip_until_end_single_quote(char *line, int *idx)
{
	(*idx)++;
	//ヌル文字までにクォートが閉じているかはvalidateで検査するが、一応チェックしておく
	while (line[*idx] != SINGLE_QUOTE && line[*idx] != '\0')
		(*idx)++;
	(*idx)++;
}

void		skip_until_end_double_quote(char *line, int *idx)
{
	(*idx)++;
	while (1)
	{
		if (line[*idx] == BACK_SLASH)
		{
			(*idx) += 2;
			continue ;
		}
		if (line[*idx] == DOUBLE_QUOTE || line[*idx] == '\0')
			break;
		(*idx)++;
	}
	(*idx)++;
}
