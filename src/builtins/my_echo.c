#include "libft.h"
#include "constants.h"

// -nオプション
// 有->endl_flag = 1
// 無->endl_flag = 0
void my_echo(char *arg, int endl_flag)
{
	ft_putstr_fd(arg, STD_OUT);
	if(!endl_flag)
		ft_putstr_fd("\n", STD_OUT);
}

#ifdef MY_ECHO_C 

int main(void)
{
	char *arg = "hello world";

	my_echo(arg, 0);
	my_echo(arg, 1);
}

#endif