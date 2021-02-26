#include "env_ctrl.h"
#include "exit_status.h"
#include <stdlib.h>
#include "constants.h"
#include "libft.h"
#include "main.h"

void		setup_shell(char **line, char **envp)
{
	if ((*line = ft_calloc(sizeof(char *), ARG_MAX + 1)) == NULL)
	{
		p_lack_of_heap_mem_err();
		exit(GENERAL_ERRORS);
	}
	// setup_signal();
	// create_env_list(envp);

	(void)envp;
}
