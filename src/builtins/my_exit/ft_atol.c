#include "libft.h"

long int	ft_atol(const char *str)
{
	int			i;
	int			flag;
	long int	n;

	i = 0;
	n = 0;
	flag = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	if (str[i] == '-')
	{
		flag = 1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	while (ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		++i;
	}
	if (flag == 1)
		n *= -1;
	return (n);
}
