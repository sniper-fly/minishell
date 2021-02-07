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

#ifdef EXEC_CMD_C

#include "main.h"
#include "parse.h"
#include "utils.h"
#include "debug.h"
#include "constants.h"
#include "read_cmd_line.h"
#include "libft.h"

int main(void)
{
	char cmd_line[ARG_MAX + 1];
	t_process **cmd_procs;

	while(TRUE)
	{
		print_prompt();
		read_cmd_line(cmd_line);
		cmd_procs = parse_cmd_line(cmd_line, &g_status);
		exec_cmd(cmd_procs);
		ft_putnbr_fd(WEXITSTATUS(g_status), 1);
		pendl();
	}
}

#endif