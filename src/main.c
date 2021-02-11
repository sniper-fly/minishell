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
	char		***str_procs;
	int			status;

	setup_signal();
	line = setup_cmd_line_buf(); //ARG_MAX + 1確保　
	while (1)
	{
		read_cmd_line(line);
		if (!is_syntax_valid(line)) //lineは再利用するのでfreeしない
			continue ;
		str_procs = convert_line2str_procs(line);
		exec_cmd(str_procs); //失敗したらstr_procsをfreeし忘れないように
		free_str_procs();
	}
	free(line);
	(void)argc; (void)argv; (void)envp;
}

#endif
