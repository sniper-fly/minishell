#include "constants.h"
#include "libft.h"
#include "struct/process.h"
#include <stdlib.h>
#include "utils.h"

t_process		**parse_cmd_line(char *line, int *status)
{
	char		**semicolon_splitted;
	char		**pipe_spilitted;
	t_process	**procs;
	int			i;
	int			j;

	*status = SUCCESS;
	semicolon_splitted = ft_split(line, ';'); //should free TODO: error処理
	//ここでプロセス行数がわかるので、行数分+1 malloc
	procs = (t_process**)ft_calloc(sizeof(t_process*),
		(count_string_arr_row(semicolon_splitted) + 1)); //TODO:error処理
	
	i = 0;
	while (semicolon_splitted[i])
	{
		pipe_spilitted = ft_split(semicolon_splitted[i], '|'); //should free TODO:error処理
		//ここで各プロセス列数がわかるので、各行における列数 + 1 malloc
		procs[i] = (t_process*)ft_calloc(sizeof(t_process),
			(count_string_arr_row(pipe_spilitted) + 1)); //TODO:error処理
		j = 0;
		while (pipe_spilitted[j])
		{
			// ここで、既に二次元配列になったコマンドラインが取得できる
			procs[i][j].cmd = ft_split(pipe_spilitted[j], ' '); //should free TODO:error処理
			j++;
		}
		free_string_arr(pipe_spilitted);
		procs[i][j].is_end = TRUE;
		i++;
	}
	free_string_arr(semicolon_splitted);
	return (procs);
}

#ifdef PARSE_CMD_LINE_C

//TODO:メモリリーク解消
#include <stdio.h>
#include "debug.h"
int		main(void)
{
	t_process	**procs;
	int			status;

	procs = parse_cmd_line("cat -e  aa  jfdk | echo aaa bb   dd | eee; hoge ; ajfsdla ; afda", &status);
	(void)status;
	show_procs(procs);
}

#endif
