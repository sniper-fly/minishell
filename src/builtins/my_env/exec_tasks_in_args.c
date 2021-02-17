#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "parse.h"
#include "execute.h"
#include "validation.h"

static char *create_cmd_line(char **args)
{
	int i;
	char *cmd_line;
	char *tmp;

	i = 1;
	while (args[i] && ft_strchr(args[i], '='))
		++i;
	cmd_line = ft_strdup(args[i]);
	++i;
	while (args[i])
	{
		tmp = ft_strjoin(cmd_line, " ");
		free(cmd_line);
		cmd_line = ft_strjoin(tmp, args[i]);
		free(tmp);
		++i;
	}
	return (cmd_line);
}

void exec_tasks_in_args(char **args)
{
	char *cmd_line;
	char ***tasks;

	cmd_line = create_cmd_line(args);
	if (!is_valid_command_line(cmd_line))
	{
		free(cmd_line);
		return ;
	}
	tasks = convert_line2tasks(cmd_line);
	exec_tasks(tasks);
	free_tasks(tasks);
	free(cmd_line);
}