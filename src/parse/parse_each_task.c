#include "struct/process.h"
#include "utils.h"
#include "libft.h"
#include "constants.h"

#ifndef DEBUG //コンパイルできないので、デバッグオプション付きの時はコンパイルしない

static t_process	*parse_cmd(char **str_procs, t_process *procs)
{
	int		i;
	char	*expanded_str;
	char	**raw_cmds;
	char	**cmds;

	i = 0;
	while (str_procs[i]) //プロセスごとに回す
	{
		expanded_str = expand_env_var_str(str_procs[i]);
		raw_cmds = split_str_by_space(expanded_str);
		cmds = cut_modifier(raw_cmds);
		procs[i].cmd = cmds;
		free_all(expanded_str, raw_cmds);
		i++;
	}
	return (procs);
}

//プロセス列を処理。扱っているのはパイプで区切られた二次元配列
t_process			*parse_each_task(char **str_procs)
{
	t_process	*procs;
	int			proc_num;
	int			i;

	proc_num = count_string_arr_row(str_procs);
	procs = ft_calloc(sizeof(t_process), proc_num + 1);
	procs[proc_num].is_end = TRUE;

	i = 0;
	while (str_procs[i])
	{
		parse_redirect(str_procs[i], &(procs[i]));
		i++;
	}
	procs = parse_cmd(str_procs, procs);
	return (procs);
}

#endif
