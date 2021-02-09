#ifdef READ_CMD_LINE_C

int main(void)
{
	char line[ARG_MAX + 1];
	read_cmd_line(line);
	ft_putstr_fd(line, STD_OUT);
}

#endif

#ifdef MAIN_C

#include "struct/process.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"
#include "utils.h"
#include "parse.h"
#include "debug.h"
#include "main.h"

int		main(void)
{
	char		line[ARG_MAX + 1];
	t_process	**procs;
	int			status;

	while (TRUE)
	{
		print_prompt();
		read_cmd_line(line);
		procs = convert_line2str_procs(line, &status);
		show_procs(procs);
	}
}

#endif
