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

t_process		**generate_simple_procs(char *line)
{
	char		**semicolon_splitted;
	char		**pipe_spilitted;
	t_process	**procs;
	int			i;
	int			j;

	cut_last_endl(line);
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
