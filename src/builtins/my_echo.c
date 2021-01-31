#include "libft.h"
#include "constants.h"

// -nオプション
// 有->endl_flag = 1
// 無->endl_flag = 0
void my_echo(char **args, int endl_flag)
{
	int	i;

	i = 0;
	while(args[i])
	{
		ft_putstr_fd(args[i], STD_OUT);
		ft_putchar_fd(' ', STD_OUT);
		++i;
	}
	if(!endl_flag)
		ft_putstr_fd("\n", STD_OUT);
}

#ifdef MY_ECHO_C 

int main(void)
{
	char *arg []= {"hello", "world", NULL};

	my_echo(arg, 0);
	my_echo(arg, 1);
}

#endif