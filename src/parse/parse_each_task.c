#include "exit_status.h"
#include "struct/process.h"
#include "utils.h"
#include "libft.h"
#include "constants.h"
#include "parse.h"
#include <stdlib.h>
#include <signal.h>

extern volatile sig_atomic_t		g_status;

static void			free_all(char *str, char **strs)
{
	free(str);
	free_string_arr(strs);
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
	procs[proc_num].is_end = TRUE;
	i = 0;
	while (str_procs[i])
	{
		if (parse_redirect(str_procs[i], &(procs[i])) == ERROR)
		{
			g_status = GENERAL_ERRORS;
			// free_single_proc(&procs[i]);
			ft_bzero(&procs[i], sizeof(t_process));
			free(str_procs[i]);
			str_procs[i] = ft_strdup("___redirect_failure___");
		}
		i++;
	}
	procs = parse_cmd(str_procs, procs);
	return (procs);
}
