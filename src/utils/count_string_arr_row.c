/*
** If null is sent, segfault
*/

int		count_string_arr_row(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
		i++;
	return (i);
}
