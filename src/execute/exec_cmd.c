#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "execute.h"
#include "struct/process.h"

extern int	g_status;

void	exec_cmd(char ***tasks)
{
	int i;
	t_process *procs;

	i = 0;
	while (tasks[i]) //行のループ
	{
		procs = NULL;	// TODO:後で消す
		procs = parse(tasks[i]);
		// TODO:procs = parse(tasks[i]);
		// TODO:create_empty_file();
		// TODO:ビルトインを実行するかどうかのチェック(前後が番兵かi.e.コマンドが単一かどうか)
		exec_pipes(procs); //パイプのwhileループ(列のループ)
		// TODO:free_procs(procs);
		++i;
	}
}
