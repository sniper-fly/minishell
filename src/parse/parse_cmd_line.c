#include "constants.h"
#include "libft.h"
#include "struct/process.h"
#include <stdlib.h>
#include "utils.h"

static void		init_process_properties(t_process *proc)
{
	ft_bzero(proc, sizeof(t_process));
}

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
	procs = (t_process**)malloc(sizeof(t_process*)
		* (count_string_arr_row(semicolon_splitted) + 1)); //TODO:error処理
	
	i = 0;
	while (semicolon_splitted[i])
	{
		pipe_spilitted = ft_split(semicolon_splitted[i], '|'); //should free TODO:error処理
		//ここで各プロセス列数がわかるので、各行における列数+1 malloc
		procs[i] = (t_process*)malloc(sizeof(t_process)
			* (count_string_arr_row(pipe_spilitted) + 1)); //TODO:error処理
		j = 0;
		while (pipe_spilitted[j])
		{
			init_process_properties(&(procs[i][j]));
			// ここで、既に二次元配列になったコマンドラインが取得できる
			procs[i][j].cmd = ft_split(pipe_spilitted[j], ' '); //should free TODO:error処理
			j++;
		}
		free_string_arr(pipe_spilitted);
		procs[i][j].is_end = TRUE;
		i++;
	}
	free_string_arr(semicolon_splitted);
	procs[i] = NULL; //末端のNULL埋め
	return (procs);
}

#ifdef PARSE_CMD_LINE_C

//TODO:メモリリーク解消
#include <stdio.h>
int		main(void)
{
	t_process	**procs;
	int			status;

	procs = parse_cmd_line("cat -e  aa  jfdk | echo aaa bb   dd | eee; hoge ; ajfsdla ; afda", &status);
	(void)status;
	for (int i = 0; procs[i]; i++)
	{
		for (int j = 0; procs[i][j].is_end != TRUE; j++)
		{
			show_string_arr(procs[i][j].cmd);
			ft_putchar_fd(',', STD_OUT);
		}
		ft_putchar_fd('\n', STD_OUT);
	}
}

#endif
