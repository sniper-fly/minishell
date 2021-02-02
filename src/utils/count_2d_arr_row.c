/*
** If null is sent, segfault
*/

int		count_2d_arr_row(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
