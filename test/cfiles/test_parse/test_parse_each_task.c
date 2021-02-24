#ifdef PARSE_EACH_TASK_C
#include "debug.h"
#include "parse.h"
#include "env_ctrl.h"
#include "builtins/builtins.h"
#include <stdlib.h>

extern char **environ;

int		main(void)
{
	char*	line[] = {
		"ls -l",
		"  ls -l  ",
		" echo \" aaa \" ",
		" 'echo' 'aaa' ",
		" echo ' \\af ' ",
		" echo \" \\af \" ",
		"\\\\\\\\\\",
		" echo hello >test/var_parse/hello",
		" echo bye >test/var_parse/hello >>test/var_parse/bye",
		" echo err 2>test/var_parse/err >test/var_parse/err <Makefile",
		NULL,
	};
	char*	envvar[] = {"export", "foo=bar", "greeting=hello", "hey=good bye", NULL};
	t_process	*procs;
	char	***tasks;

	create_env_list(environ);
	my_export(envvar);

	for (int i = 0; line[i]; i++)
	{
		tasks = convert_line2tasks(line[i]); //それぞれのlineについてtasksを形成
		// show_tasks(tasks);
		for (int j = 0; tasks[j]; j++)
		{
			procs = parse_each_task(tasks[j]); //行のループ
			for (int k = 0; procs[k].is_end != TRUE; k++)
				show_proc_property(&procs[k]);
		}
		free_tasks(tasks);
	}
}

#endif