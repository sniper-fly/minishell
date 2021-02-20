#include "utils.h"
#include "struct/t_bool.h"
#include "builtins/builtins.h"

extern int g_status;

const char *g_builtin_func_names[] =
{
	"echo",
	"cd",
	"pwd",
	"export",
	"unset",
	"env",
	"exit"
};

int (*g_builtin_func_ptrs[])(char **) =
{
	&my_echo,
	&my_cd,
	&my_pwd,
	&my_export,
	&my_unset,
	&my_env,
	&my_exit
};

void exec_builtins(char **args)
{
	int i;

	i = 0;
	while(i < 7)
	{
		if(!ft_strcmp(args[0], (char *)g_builtin_func_names[i]))
		{
			g_status = g_builtin_func_ptrs[i](args);
		}
		++i;
	}
}