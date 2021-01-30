#include "libft.h"
#include "constants.h"

// -nオプション
// 有->endl_flag = 1
// 無->endl_flag = 0
void echo(char *str, int endl_flag)
{
	ft_putstr_fd(str, STD_OUT);
	if(endl_flag)
		ft_putstr_fd("\n", STD_OUT);
}