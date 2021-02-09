#include "parse.h"

static void	skip_until_end_quote(char *line, int *idx)
{
	char	quote;

	quote = line[*idx];
	(*idx)++;
	//ヌル文字までにクォートが閉じているかはvalidateで検査するが、一応チェックしておく
	while (line[*idx] != quote && line[*idx] != '\0')
		(*idx)++;
	(*idx)++;
}

void		replace_meta_with_divider(char *line, char rplced_ch)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			skip_until_end_quote(line, &i);
			continue ;
		}
		else if (line[i] == '\\' && line[i + 1] == rplced_ch)
		{
			i += 2; //ヌル終端は保証されているのでセグフォしない
			continue ;
		}
		if (line[i] == rplced_ch)
			line[i] = DIVIDER;
		i++;
	}
}
