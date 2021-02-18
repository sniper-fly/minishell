// #ifdef EXPAND_ENV_VAR_STR_C
#include "parse.h"
#include "env_ctrl.h"
#

int		main(void)
{
	char*	
}

#endif


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
