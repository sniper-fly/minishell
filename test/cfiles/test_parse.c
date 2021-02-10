#ifdef CONVERT_LINE2STR_PROCS_C

//TODO:メモリリーク解消
#include <stdio.h>
#include "debug.h"
#include "parse.h"
#include "libft.h"
#include "constants.h"
#include "utils.h"

static void	p_test(char *line, int i)
{
	char		***str_procs;

	str_procs = convert_line2str_procs(line);
	ft_putstr_fd("line", STD_OUT);
	ft_putnbr_fd(i, STD_OUT);
	pendl();
	show_str_procs(str_procs);
	ft_putstr_fd("=======================\n", STD_OUT);
}

int		main(void)
{
	char		line0[] = "cmd | cmd1 | cmd 2 ; echo | echo ; hello";
	char		line1[] = "cmd \";\" \"|\"| cmd1 \";\" | ";
	char		line2[] = "cmd \\; aaa; bbb \\|\\; | cc; a";
	char		line3[] = "cmd ';;' aa | cmd1 '|''|' | cmd 2 'a;' ; echo | echo ; hello";

	p_test(line0, 0);
	p_test(line1, 1);
	p_test(line2, 2);
	p_test(line3, 3);
}

#endif

#ifdef REPLACE_META_WITH_DIVIDER_C
#include <stdio.h>

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