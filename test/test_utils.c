
#ifdef FT_PERROR_C

#include <fcntl.h>
int		main(void)
{
	open("aaaa", 0);
	ft_perror("aa");
}

#endif