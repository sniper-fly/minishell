#include "libft.h"	//
#include "utils.h"
#include "constants.h"	//
#include "struct/t_bool.h"
#include "builtins/builtins.h"

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

void (*g_builtin_func_ptrs[])(char **) =
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
			g_builtin_func_ptrs[i](args);
		}
		++i;
	}
}