#include "parse.h"
#include "libft.h"
#include "utils.h"

char		**cut_all_cmds_modifier(char **raw_cmds)
{
	char	**cmds;
	int		i;

	cmds = ft_calloc(sizeof(char**), count_string_arr_row(raw_cmds) + 1);
	if (cmds == NULL)
		return (NULL);
	i = 0;
	while (raw_cmds[i])
	{
		cmds[i] = raw_cmds[i];
		i++;
	}
	return (cmds);
}
