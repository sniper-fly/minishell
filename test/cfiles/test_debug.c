#ifdef FREE_PROCS_C

#include "debug.h"
#include "parse.h"
int		main(void)
{
	t_process	**procs;
	int			status;

	procs = parse_cmd_line("cat -e  aa  jfdk | echo aaa bb   dd | eee; hoge ; ajfsdla ; afda", &status);
	(void)status;
	(void)procs;
	show_procs(procs);
	free_procs(procs);
}

#endif

#ifdef GENERATE_SIMPLE_PROCS_C

#include "debug.h"
int		main(void)
{
	t_process	**procs;

	procs = generate_simple_procs("cat -e  aa  jfdk | echo aaa bb   dd | eee; hoge ; ajfsdla ; afda");
	show_procs(procs);
}

#endif

#ifdef SHOW_STRING_ARR_C
#include "debug.h"

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