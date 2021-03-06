#include "libft.h"
#include "constants.h"
#include "utils.h"
#include <stddef.h>

static void	putstr_with_db_quote(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("NULL", STD_OUT);
		return ;
	}
	ft_putchar_fd('"', STD_OUT);
	ft_putstr_fd(str, STD_OUT);
	ft_putchar_fd('"', STD_OUT);
}

void		show_string_arr(char **strings)
{
	int	i;

	ft_putchar_fd('{', STD_OUT);
	putstr_with_db_quote(strings[0]);
	if (strings[0] == NULL)
	{
		ft_putchar_fd('}', STD_OUT);
		return ;
	}
	i = 1;
	while (strings[i])
	{
		ft_putstr_fd(", ", STD_OUT);
		putstr_with_db_quote(strings[i]);
		i++;
	}
	ft_putchar_fd('}', STD_OUT);
}
