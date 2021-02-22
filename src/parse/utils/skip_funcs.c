#include "utils.h"

void		skip_space_idx(char *str, int *i)
{
	while (ft_isspace(str[*i]))
	{
		(*i)++;
	}
}
