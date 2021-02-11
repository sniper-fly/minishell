#ifdef FREE_PROCS_C

#include "debug.h"
#include "parse.h"

static void leak_test(void)
{
	t_process	**procs;

	procs = generate_simple_procs("cat -e  aa  jfdk | echo aaa bb   dd | eee; hoge ; ajfsdla ; afda");
	show_procs(procs);
	free_procs(procs);
}

int		main(void)
{
	int hoge;
	leak_test();
	(void)hoge;
}

#endif

//上でテストしているので削除
// #ifdef GENERATE_SIMPLE_PROCS_C

// #include "debug.h"
// int		main(void)
// {
// 	t_process	**procs;

// 	procs = generate_simple_procs("cat -e  aa  jfdk | echo aaa bb   dd | eee; hoge ; ajfsdla ; afda");
// 	show_procs(procs);
// }

// #endif

#ifdef SHOW_STRING_ARR_C
#include "debug.h"
#include "utils.h"
#include <stddef.h>

int		main(void)
{
	char* hoge0[] = {"cat", "hoge", "endl", "-l", NULL};
	char* hoge1[] = {NULL};
	char* hoge2[] = {"", "", "dog", NULL};
	char* hoge3[] = {"", "\"", "dog", NULL};

	show_string_arr(hoge0);
	pendl();
	show_string_arr(hoge1);
	pendl();
	show_string_arr(hoge2);
	pendl();
	show_string_arr(hoge3);
	pendl();
}

#endif

#ifdef EXEC_CMD_FOR_DEBUG_C

#include <sys/wait.h>
#include "execute.h"
#include "main.h"
#include "parse.h"
#include "utils.h"
#include "debug.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"

int g_status;

int main(void)
{
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = generate_simple_procs(cmd_line);
		exec_cmd_for_debug(cmd_procs);
		ft_putnbr_fd(WEXITSTATUS(g_status), 1);
		pendl();
	}
}

#endif