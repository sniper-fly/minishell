#include "read_cmd_line.h"

#ifndef DEBUG

int		main(int argc, char **argv, char **envp)
{
	char	line[ARG_MAX];

	setup_signal();
	while (1)
	{
		read_cmd_line(line);
		parse_line();
		create_empty_file(); // open とclose
		exec_cmd();

		free_line();
		free_list();
	}
	(void)argc; (void)argv; (void)envp;
}

#endif
