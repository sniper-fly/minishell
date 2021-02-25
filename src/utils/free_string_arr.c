#include <stdlib.h>

void	free_string_arr(char **strings)
{
	int	i;

	if (strings == NULL)
		return ;
	i = 0;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}
