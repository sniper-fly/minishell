#include "struct/process.h"
#include "constants.h"
#include "utils.h"
#include <stdlib.h>

void		free_procs(t_process **procs)
{
	int		i;
	int		j;

	i = 0;
	while (procs[i])
	{
		j = 0;
		while (procs[i][j].is_end != TRUE)
		{
			free_string_arr(procs[i][j].cmd);
			free(procs[i][j].red_in_file_name);
			free(procs[i][j].red_out_file_name);
			j++;
		}
		free(procs[i]);
		i++;
	}
	free(procs);
}

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
