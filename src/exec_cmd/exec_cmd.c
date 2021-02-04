#include <unistd.h>
#include <sys/wait.h>
#include "exec_cmd.h"
#include "struct/process.h"

int g_status;

void	exec_cmd(t_process **procs)
{
	int i;

	i = 0;
	while (procs[i]) //行のループ
	{
		// TODO:ビルトインを実行するかどうかのチェック(前後が番兵かi.e.コマンドが単一かどうか)
		if (fork())
			wait(&g_status);
		else
			exec_pipes(procs[i]); //パイプのwhileループ(列のループ)
		++i;
	}
}

#ifdef EXEC_CMD_C

#include "main.h"
#include "parse.h"
#include "utils.h"
#include "debug.h"
#include "constants.h"
#include "read_cmd_line.h"

int main(void)
{
	int i;
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = parse_cmd_line(cmd_line, &g_status);
		i = 0;
		while(cmd_procs[i])
		{
			exec_pipes(cmd_procs[i]);
			++i;
		}
	}
}

#endif