#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "exec_cmd.h"
#include "struct/process.h"

extern int	g_status;

void	exec_cmd(t_process **procs)
{
	int i;

	i = 0;
	while (procs[i]) //行のループ
	{
		// TODO:ビルトインを実行するかどうかのチェック(前後が番兵かi.e.コマンドが単一かどうか)
		exec_pipes(procs[i]); //パイプのwhileループ(列のループ)
		++i;
	}
}
