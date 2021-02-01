#include "libft.h"

void	putchar_times_fd(char ch, int times, int fd)
{
	int		i;

	i = 0;
	while (i < times)
	{
		ft_putchar_fd(ch, fd);
		i++;
	}
}
