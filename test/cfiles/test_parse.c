
#ifdef GET_SINGLE_ENV_KEY_C
#include "parse.h"
#include <stdio.h>
#include "libft.h"
#include "constants.h"
#include <stdlib.h>
#include "utils.h"

void	test_get_single_env_key(char *str, int idx)
{
	static int num = 1;
	char	*tmp = get_single_env_key(str, idx);

	ft_putnbr_fd(num, STD_OUT);
	pendl();
	ft_putendl_fd(tmp, STD_OUT);
	ft_putendl_fd("=============", STD_OUT);
	free(tmp);
	num++;
}

int		main(void)
{
	char str1[] = "$world";
	char str2[] = "$\"\"world";
	char str3[] = "$world$hoge";
	char str4[] = "$hey ";
	char str5[] = "$hey\t ";
	char str6[] = "a$hey\"";
	char str7[] = "ab$hey\\";
	char str8[] = "a$hey'";
	char str9[] = "$$hey'";

	test_get_single_env_key(str1, 1);
	test_get_single_env_key(str2, 1);
	test_get_single_env_key(str3, 1);
	test_get_single_env_key(str4, 1);
	test_get_single_env_key(str5, 1);
	test_get_single_env_key(str6, 2);
	test_get_single_env_key(str7, 3);
	test_get_single_env_key(str8, 2);
	test_get_single_env_key(str9, 2);
	test_get_single_env_key(str9, 1);
}

#endif

#ifdef AUTO_RESIZE_CPY_C
#include <stdlib.h>
#include "parse.h"
#include <stdio.h>
#include "libft.h"

static void leak_test_func1(void)
{
	char	*dst;
	char	src[] = "hello wo";
	int		buf_size;

	buf_size = 10;
	dst = malloc(sizeof(char) * buf_size);
	for (int i = 0; src[i]; i++)
		dst = auto_resize_cpy(dst, i, &buf_size, src[i]);
	ft_putendl_fd(dst, 1);
	free(dst);
}

static void leak_test_func2(void)
{
	char	*dst;
	char	src[] = "hello world hoge hey foo bar baz";
	int		buf_size;

	buf_size = 10;
	dst = malloc(sizeof(char) * buf_size);
	for (int i = 0; src[i]; i++)
		dst = auto_resize_cpy(dst, i, &buf_size, src[i]);
	ft_putendl_fd(dst, 1);
	free(dst);
}

int		main(void)
{
	leak_test_func1();
	leak_test_func2();
}

#endif

#ifdef CONVERT_LINE2TASKS_C

#include <stdio.h>
#include "debug.h"
#include "parse.h"
#include "libft.h"
#include "constants.h"
#include "utils.h"

static void	p_test(char *line, int i)
{
	char		***tasks;

	tasks = convert_line2tasks(line);
	ft_putstr_fd("line", STD_OUT);
	ft_putnbr_fd(i, STD_OUT);
	pendl();
	show_tasks(tasks);
	free_tasks(tasks);
	ft_putstr_fd("=======================\n", STD_OUT);
}

int		main(void)
{
	char		line0[] = "cmd | cmd1 | cmd 2 ; echo | echo ; hello";
	char		line1[] = "cmd \";\" \"|\"| cmd1 \";\" | ";
	char		line2[] = "cmd \\; aaa; bbb \\|\\; | cc; a";
	char		line3[] = "cmd ';;' aa | cmd1 '|''|' | cmd 2 'a;' ; echo | echo ; hello";
	char		line4[] = {'c', 'm', 'd', ' ', '"', 'a', '\\', '"', ';', '"', '\0'}; //echo "a\";"

	p_test(line0, 0);
	p_test(line1, 1);
	p_test(line2, 2);
	p_test(line3, 3);
	p_test(line4, 4);
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