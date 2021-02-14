int		ft_strcmp(char *s1, char *s2)
{
	int d;

	while (*s1 || *s2)
	{
		d = *s1 - *s2;
		if (d)
			return (d);
		++s1;
		++s2;
	}
	return (0);
}
