#include "struct/process.h"
#include "utils.h"
#include "libft.h"
#include "constants.h"
#include "parse.h"
#include <stdlib.h>

static void			free_all(char *str, char **strs)
{
	free(str);
	free_string_arr(strs);
}

//リダイレクトが失敗したときに、exit statusが一で常にリターンする関数が必要
static char			**get_redir_fail_cmd(void)
{
	char	**none_cmd;

	none_cmd = ft_calloc(sizeof(char*), 3);
	none_cmd[0] = ft_strdup("___redirect_failure___"); //TODO:
	none_cmd[1] = NULL;
	return (none_cmd);
}

static t_process	*parse_cmd(char **str_procs, t_process *procs)
{
	int		i;
	char	*expanded_str;
	char	**raw_cmds;

	i = 0;
	while (str_procs[i]) //プロセスごとに回す
	{
		expanded_str = expand_env_var_str(str_procs[i]);
		raw_cmds = split_str_by_space(expanded_str);
		procs[i].cmd = cut_all_cmds_modifier(raw_cmds);
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
	procs = ft_calloc(sizeof(t_process), proc_num + 1); //TODO:
	if (procs == NULL)
		return (NULL);
	procs[proc_num].is_end = TRUE;
	i = 0;
	while (str_procs[i])
	{
		if (parse_redirect(str_procs[i], &(procs[i])) == ERROR)
			procs[i].cmd = get_redir_fail_cmd();
		i++;
	}
	procs = parse_cmd(str_procs, procs);
	return (procs);
}
