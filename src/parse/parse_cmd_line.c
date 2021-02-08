#include "constants.h"
#include "libft.h"
#include "struct/process.h"
#include <stdlib.h>
#include "utils.h"

static void		cut_last_endl(char *line)
{
	char	*endl_ptr;

	endl_ptr = ft_strchr(line, '\n');
	if (endl_ptr)
		*endl_ptr = '\0';
}

char		***parse_cmd_line(char *line)
{
	char		**semicolon_splitted;
	char		**pipe_spilitted;
	char		***str_procs;
	int			i;

	cut_last_endl(line);
	semicolon_splitted = ft_split(line, ';'); //should free TODO: error処理
	//ここでプロセス行数がわかるので、行数分+1 malloc
	str_procs = (char***)ft_calloc(sizeof(char**),
		(count_string_arr_row(semicolon_splitted) + 1)); //TODO:error処理

	i = 0;
	while (semicolon_splitted[i])
	{
		pipe_spilitted = ft_split(semicolon_splitted[i], '|'); //should free TODO:error処理
		str_procs[i] = pipe_spilitted;
		i++;
	}
	free_string_arr(semicolon_splitted);
	return (str_procs);
}


#ifdef PARSE_CMD_LINE_C

//TODO:メモリリーク解消
#include <stdio.h>
#include "debug.h"
int		main(void)
{
	char		***str_procs;
	char		*line = "cmd | cmd1 | cmd 2 ; echo | echo ; hello";

	str_procs = parse_cmd_line(line);
	show_str_procs(str_procs);
}

#endif
