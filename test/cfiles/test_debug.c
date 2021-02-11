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
#include "utils.h"
#include "parse.h"
#include "utils.h"
#include "debug.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"
#include "env_ctrl.h"

extern int g_status;

void	test_exec_cmd(char *cmd_line)
{
	t_process **cmd_proc;

	cmd_proc = generate_simple_procs(cmd_line);
	ft_putstr_fd("===============\n", STD_OUT);
	exec_cmd_for_debug(cmd_proc);
	ft_putstr_fd("status:", STD_OUT);
	ft_putnbr_fd(WEXITSTATUS(g_status), STD_OUT);
	pendl();
}

int main(int argc, char *argv[], char *envp[])
{
	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);

	char cmd0[] = "echo hello world";
	char cmd1[] = "/bin/ls -l | wc -l";
	// char cmd2[] = "du -a | wc -l ; echo fin";
	char cmd3[] = "echo hello | /bin";
	char cmd4[] = "noexist";
	char cmd5[] = "/bin/noexist";
	char cmd6[] = "echo hogehoge | noexist";

	test_exec_cmd(cmd0);
	test_exec_cmd(cmd1);
	// test_exec_cmd(cmd2);
	test_exec_cmd(cmd3);
	test_exec_cmd(cmd4);
	test_exec_cmd(cmd5);
	test_exec_cmd(cmd6);
}

#endif