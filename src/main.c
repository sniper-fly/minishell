#include <signal.h>
#include "read_cmd_line.h"
#include "constants.h"
#include "struct/process.h"
#include "parse.h"
#include "libft.h"
#include "main.h"
#include "execute.h"
#include <stdlib.h>
#include "struct/env_list.h"
#include "exit_status.h"

t_env_list				*g_env_list;
int						g_status = SUCCEEDED;
volatile sig_atomic_t	g_is_reading_cmd_line;

#ifndef DEBUG

int		main(int argc, char **argv, char **envp)
{
	char		*line;
	char		***tasks;

	setup_shell(&line, envp);
	while (TRUE)
	{
		print_prompt();
		read_cmd_line(line);
		if (is_full_of_space(line))
			continue ;
		if (!is_valid_command_line(line)) //lineは再利用するのでfreeしない
		{
			g_status = SYNTAX_ERROR; //exit statusの名前設定NOTE:
			continue ;
		}
		tasks = convert_line2tasks(line); //TODO:
		exec_tasks(tasks); //失敗したらtasksをfreeし忘れないように
		free_tasks(tasks);
	}
	free(line);
	(void)argc; (void)argv; (void)envp;
}

#endif
