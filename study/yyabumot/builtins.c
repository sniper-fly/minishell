#include "tutorials.h"

char **ft_realloc(char **src, char **new)
{
	int i;
	int j;
	char **dest;

	dest = malloc(sizeof(char**)*((sizeof(src)+sizeof(new))/sizeof(char*)-1));

	i = 0;
	j = 0;
	while(src[j]){
		dest[i] = ft_strdup(src[j]);
		++i;
		++j;
	}
	j = 0;
	while(new[j]){
		dest[i] = ft_strdup(new[j]);
		++i;
		++j;
	}
	return dest;
}

int exec_cd(char **arg)
{
	if(chdir(arg[1]))
		perror("cd");
}

int exec_export(char **arg)
{
	return 1;
}

int exec_unset(char **arg)
{
	return 1;
}

int exec_exit(char **arg)
{
	exit(0);
}