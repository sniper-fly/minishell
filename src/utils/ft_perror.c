#include <stdio.h>
#include "libft.h"
#include "constants.h"
#include <string.h>
#include <errno.h>

void		ft_perror(char *str)
{
	if (str != NULL && str[0] != '\0')
	{
		ft_putstr_fd(str, STD_ERR);
		ft_putstr_fd(": ", STD_ERR);
	}
	ft_putstr_fd(strerror(errno), STD_ERR);
	ft_putchar_fd('\n', STD_ERR);
}

#ifdef FT_PERROR_C

#include <fcntl.h>
int		main(void)
{
	open("aaaa", 0);
	ft_perror("aa");
}

#endif
