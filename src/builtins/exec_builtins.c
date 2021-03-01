#include "utils.h"
#include "struct/t_bool.h"
#include "builtins/builtins.h"
#include <stddef.h>
#include <signal.h>

extern volatile sig_atomic_t g_status;

const char *g_builtin_func_names[] =
{
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit",
	"___redirect_failure___",
	NULL
};

int (*g_builtin_func_ptrs[])(char **) =
{
	&my_echo,
	&my_cd,
	&my_pwd,
	&my_export,
	&my_unset,
	&my_env,
	&my_exit,
	&redir_fail_cmd
};

void	exec_builtins(char **args)
{
	int	i;
	int	sum_builtins;

	i = 0;
	sum_builtins = count_string_arr_row((char**)g_builtin_func_names);
	while (i < sum_builtins)
	{
		if (!ft_strcmp((char *)g_builtin_func_names[i], args[0]))
		{
			g_status = g_builtin_func_ptrs[i](args);
			return ;
		}
		++i;
	}
}
