#include <unistd.h>
#include "constants.h"
#include <stdlib.h>
#include "libft.h"
#include "read_cmd_line.h"
#include "utils.h"
#include <signal.h>

extern volatile sig_atomic_t	g_status;
extern volatile sig_atomic_t	g_is_reading_cmd_line;

static t_bool	is_there_endl(char *line)
{
	if (ft_strchr(line, '\n'))
		return (TRUE);
	return (FALSE);
}

static int		read_cmd_line_recursive(char *line, int size_has_read)
{
	int		actual_read_size;

	g_is_reading_cmd_line = TRUE;
	actual_read_size =
		read(STD_IN, &line[size_has_read], ARG_MAX - size_has_read);
	g_is_reading_cmd_line = FALSE;
	if (actual_read_size == ERROR)
	{
		ft_perror("minishell");
		return (ERROR);
	}
	else if (actual_read_size == ARG_MAX - size_has_read)
	{
		ft_putstr_fd(
			"minishell: Input reached maximum size(ARG_MAX)\n", STD_ERR);
		return (ERROR);
	}
	if (!is_there_endl(line))
	{
		read_cmd_line_recursive(line, ft_strlen(line));
	}
	return (0);
}

int				read_cmd_line(char *line)
{
	int		actual_read_size;

	ft_bzero(line, ARG_MAX + 1);
	g_is_reading_cmd_line = TRUE;
	actual_read_size = read(STD_IN, line, ARG_MAX);
	g_is_reading_cmd_line = FALSE;
	if (line[0] == '\0')
	{
		ft_putendl_fd("exit", STD_ERR);
		exit(g_status);
	}
	else if (actual_read_size == ERROR)
	{
		ft_perror("minishell");
		return (ERROR);
	}
	else if (actual_read_size == ARG_MAX)
	{
		ft_putstr_fd("minishell: Input reached maximum size.\n", STD_ERR);
		return (ERROR);
	}
	if (!is_there_endl(line))
		read_cmd_line_recursive(line, ft_strlen(line));
	return (0);
}
