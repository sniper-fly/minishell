#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "parse.h"
#include "utils.h"
#include "execute.h"
#include "struct/t_bool.h"
#include "struct/process.h"
#include "builtins/builtins.h"

extern int	g_status;

static t_bool	should_exec_builtin_func(t_process *procs)
{
	if (procs[1].is_end != TRUE)
		return (FALSE);
	if (is_builtin_func(procs[0].cmd[0]))
		return (TRUE);
	return (FALSE);
}

void			exec_tasks(char ***tasks)
{
	int			i;
	t_process	*procs;

	i = 0;
	while (tasks[i]) //行のループ
	{
		if (!(procs = parse_each_task(tasks[i])))
		{
			g_status = malloc_error();
			++i;
			continue;
		}
		if (should_exec_builtin_func(procs))
			exec_builtins(procs[0].cmd);
		else
			exec_cmds(procs); //パイプのwhileループ(列のループ)
		// TODO:free_procs(procs);
		++i;
	}
}
