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

#ifdef REPLACE_META_WITH_DIVIDER_C
#include <stdio.h>

static void	test_replace_meta_with_divider(char *line, char rplced_ch)
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
			line[i] = '@'; //非表示文字だと確認できないので変更
		i++;
	}
}

static void	p_test(char *line, int i)
{
	printf("line%d: %s\n", i, line);
	test_replace_meta_with_divider(line, ';');
	printf("line%d: %s\n", i, line);
	printf("---------------------\n");
}

int	main(void)
{
	char line0[] = "cmd ; aaa ; bbb ; ccc 'jfka;;a;'a ; hoge\\; ;; ls \"a;a\" ";
	char line1[] = "cmd ; aaa ; bbb";
	char line2[] = "hoge 'jfka;;a;'a ; hoge;";
	char line3[] = "aaa \"hoge;f;oo\", ; a ls; ;a";
	char line4[] = "aaa;bbb;ccc\\;foo;o";

	p_test(line0, 0);
	p_test(line1, 1);
	p_test(line2, 2);
	p_test(line3, 3);
	p_test(line4, 4);
}

#endif