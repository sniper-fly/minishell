#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "execute.h"
#include "struct/process.h"

extern int	g_status;

void	exec_cmd(char ***str_procs)
{
	int i;
	t_process *procs;

	i = 0;
	while (str_procs[i]) //行のループ
	{
		procs = parse(str_procs[i]);
		create_empty_file();
		// TODO:ビルトインを実行するかどうかのチェック(前後が番兵かi.e.コマンドが単一かどうか)
		exec_pipes(procs); //パイプのwhileループ(列のループ)
		free_procs(procs);
		++i;
	}
}
