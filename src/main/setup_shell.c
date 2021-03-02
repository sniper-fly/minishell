#include "setup_signal.h"
#include <signal.h>
#include "env_ctrl.h"
#include "exit_status.h"
#include <stdlib.h>
#include "constants.h"
#include "libft.h"
#include "main.h"

extern volatile sig_atomic_t g_status;

void		setup_shell(char **line, char **envp)
{
	if ((*line = ft_calloc(sizeof(char *), ARG_MAX + 1)) == NULL)
	{
		p_lack_of_heap_mem_err();
		exit(GENERAL_ERRORS);
	}
	setup_signal();
	if (create_env_list(envp) == ERROR)
		exit(g_status);
	if (init_pwd() == ERROR)
		exit(g_status);
	(void)envp;
}
