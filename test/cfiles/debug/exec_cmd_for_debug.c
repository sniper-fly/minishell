#include "execute.h"
#include "struct/process.h"
#include <signal.h>

extern volatile sig_atomic_t	g_status;

void	exec_cmd_for_debug(t_process **procs)
{
	int i;

	i = 0;
	while (procs[i])
	{
		exec_cmds(procs[i]);
		++i;
	}
}
