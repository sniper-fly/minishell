#include <stdlib.h>
#include "libft.h"

char	*join_cmd_to_path(char *cmd, char *path_ptr)
{
	char	*add_slash;
	char	*cmd_path;

	add_slash = NULL;
	if (path_ptr[ft_strlen(path_ptr) - 1] != '/')
	{
		if (!(add_slash = ft_strjoin(path_ptr, "/")))
			return (NULL);
		if (!(cmd_path = ft_strjoin(add_slash, cmd)))
			return (NULL);
	}
	else
	{
		if (!(cmd_path = ft_strjoin(path_ptr, cmd)))
			return (NULL);
	}
	free(add_slash);
	return (cmd_path);
}
