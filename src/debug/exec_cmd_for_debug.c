#include "execute.h"
#include "struct/process.h"
#include <signal.h>

extern volatile sig_atomic_t	g_status;

void	exec_cmd_for_debug(t_process **procs)
{
	int i;

	i = 0;
	while (procs[i]) //行のループ
	{
		// TODO:ビルトインを実行するかどうかのチェック(前後が番兵かi.e.コマンドが単一かどうか)
		exec_cmds(procs[i]); //パイプのwhileループ(列のループ)
		++i;
	}
}
