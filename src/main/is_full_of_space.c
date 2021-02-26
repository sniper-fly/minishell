#include "struct/t_bool.h"
#include "utils.h"

t_bool		is_full_of_space(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
