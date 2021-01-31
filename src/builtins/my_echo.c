#include "libft.h"
#include "constants.h"

void my_echo(char **args)
{
	int idx;
	int endline_flag;	// 行末に改行を入れるかどうかのフラグ

	if(!ft_strncmp(args[1], "-n", ft_strlen(args[1])))
	{
		// -nオプションあり
		idx = 2;
		endline_flag = 0;
	}
	else
	{
		// -nオプションなし
		idx = 1;
		endline_flag = 1;
	}
	while(args[idx])
	{
		ft_putstr_fd(args[idx], STD_OUT);
		if(args[idx+1])
			ft_putchar_fd(' ', STD_OUT);
		++idx;
	}
	if(endline_flag)
		ft_putstr_fd("\n", STD_OUT);
}

#ifdef MY_ECHO_C 

int main(void)
{
	char *args[]= {"echo", "hello", NULL};

	my_echo(args);
}

#endif