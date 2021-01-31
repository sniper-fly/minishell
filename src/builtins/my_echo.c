#include "libft.h"
#include "constants.h"

// If there is an error in argument, return 1.
static int is_valid_argument(char **args)
{
	int i;

	i = 0;
	while(args[i])
		++i;
	if(i - 1 == 0)
		return 1;
	return 0;
}

void set_idx_and_endline_flag(char **args, int *idx, int *endline_flag)
{
	int	j;

	*idx = 1;
	*endline_flag = 1;
	while(args[*idx])
	{
		if(args[*idx][0] != '-')
			return ;
		j = 1;
		while(args[*idx][j])
		{
			if(args[*idx][j] != 'n')
				return ;
			++j;
		}
		*endline_flag = 0;
		++(*idx);
	}
}

#include <stdio.h>
void my_echo(char **args)
{
	int idx;
	int endline_flag;	// 行末に改行を入れるかどうかのフラグ

	if(!is_valid_argument(args))
	{
		set_idx_and_endline_flag(args, &idx, &endline_flag);
		while(args[idx])
		{
			ft_putstr_fd(args[idx], STD_OUT);
			if(args[idx + 1])
				ft_putchar_fd(' ', STD_OUT);
			++idx;
		}
	}
	if(endline_flag)
		ft_putstr_fd("\n", STD_OUT);
}

#ifdef MY_ECHO_C 

int main(void)
{
	// char *args[] = {"echo", "hello1", NULL};
	// char *args2[] = {"echo", "-nn", NULL};
	// char *args3[] = {"echo", "-nnnnnnn", NULL};
	// char *args4[] = {"echo", "-nnnnnnn", "hello", NULL};
	// char *args5[] = {"echo", "-n", "-n", "-n", NULL};
	// char *args6[] = {"echo", "-n", "-n", "6", "6", NULL};
	// char *args7[] = {"echo", "-n4", NULL};
	// char *args8[] = {"echo", "-n!", NULL};
	// char *args9[] = {"echo", "-n", NULL};
	// char *args10[] = {"echo", "-n", "world10", NULL};
	// char *args11[] = {"echo", "-n", "hello11", "world", NULL};

	char *args12[] = {"echo", "hoge", "\n", NULL};
	// char *args13[] = {"echo", "hoge", "fuga", NULL};

	// char *args14[] = {"echo", NULL};

	// my_echo(args);	//ok
	// my_echo(args2);
	// my_echo(args3);
	// my_echo(args4);
	// my_echo(args5);
	// my_echo(args6);
	// my_echo(args7);
	// my_echo(args8);
	// my_echo(args9);
	// my_echo(args10);
	// my_echo(args11);
	my_echo(args12);
	// my_echo(args13);
	// my_echo(args14);	//ok
}

#endif
