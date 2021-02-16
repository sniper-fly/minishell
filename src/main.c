#include "struct/env_list.h"

t_env_list	*g_env_list;
int			g_status;

#ifndef DEBUG

#include "read_cmd_line.h"
#include "constants.h"
#include "struct/process.h"
#include "parse.h"

int		main(int argc, char **argv, char **envp)
{
	char		*line;
	char		***tasks;
	int			status;

	setup_signal();
	line = setup_cmd_line_buf(); //ARG_MAX + 1確保　
	while (1)
	{
		read_cmd_line(line);
		if (!is_syntax_valid(line)) //lineは再利用するのでfreeしない
			continue ;
		tasks = convert_line2tasks(line);
		exec_cmd(tasks); //失敗したらtasksをfreeし忘れないように
		free_tasks(tasks);
	}
	free(line);
	(void)argc; (void)argv; (void)envp;
}

#endif
