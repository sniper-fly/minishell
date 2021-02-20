#include "parse.h"
#include "constants.h"

static void	skip_until_end_single_quote(char *line, int *idx)
{
	(*idx)++;
	//ヌル文字までにクォートが閉じているかはvalidateで検査するが、一応チェックしておく
	while (line[*idx] != SINGLE_QUOTE && line[*idx] != '\0')
		(*idx)++;
	(*idx)++;
}

static void	skip_until_end_double_quote(char *line, int *idx)
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

void		replace_meta_with_divider(char *line, char rplced_ch)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == SINGLE_QUOTE)
		{
			skip_until_end_single_quote(line, &i);
			continue ;
		}
		else if (line[i] == DOUBLE_QUOTE)
		{
			skip_until_end_double_quote(line, &i);
			continue ;
		}
		else if (line[i] == BACK_SLASH && line[i + 1] == rplced_ch)
		{
			i += 2; //ヌル終端は保証されているのでセグフォしない
			continue ;
		}
		if (line[i] == rplced_ch)
			line[i] = DIVIDER;
		i++;
	}
}
