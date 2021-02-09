#include "struct/env_list.h"

t_env_list	*g_env_list;
int			g_status;

#ifndef DEBUG

#include "read_cmd_line.h"
#include "constants.h"
#include "struct/process.h"

int		main(int argc, char **argv, char **envp)
{
	char		line[ARG_MAX + 1];
	t_process	**procs;
	int			status;

	setup_signal();
	while (1)
	{
		read_cmd_line(line);
		procs = parse_line(line, &status);
		create_empty_file(); // open とclose
		exec_cmd();

		free_line();
		free_list();
	}
	(void)argc; (void)argv; (void)envp;
}

#endif

#ifdef MAIN_C

#include "struct/process.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"
#include "utils.h"
#include "parse.h"
#include "debug.h"
#include "main.h"

int		main(void)
{
	char		line[ARG_MAX + 1];
	t_process	**procs;
	int			status;

	while (TRUE)
	{
		print_prompt();
		read_cmd_line(line);
		procs = convert_line2str_procs(line, &status);
		show_procs(procs);
	}
}

#endif