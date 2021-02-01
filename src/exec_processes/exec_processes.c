#include <unistd.h>
#include "utils.h"
#include "builtins.h"
#include "struct/t_bool.h"
#include "struct/data_list.h"

//!!!現状コンパイルできません。!!!大枠を示したただの参考資料です。

static t_bool should_exec_builtins(t_process_list *proc_lst)
{
	int i;

	i = 0;
	if (proc_lst->prev != proc_lst || proc_lst->next != proc_lst)
		return FALSE;
	while(builtin_command_names[i])
	{
		if(!ft_strcmp(builtin_command_names[i], proc_lst->cmd->arg))
			return TRUE;
		++i;
	}
	return FALSE;
}

void	exec_cmds()
{
	//並列にforkする
	// forkしたプロセスの中でまずビルトインかどうか調べる
	//ビルトインリストになければmy_execve(t_cmd_list)

	// waitpid()
	// for wait()
}

/////  exec_cmdsで、どうやって最後に終了したプロセスの終了ステータスを取得するか
//  for(i = 0; i < cmd_len; i++)
//  {
//         wait(&status);
// 		if (status != 0)
// 			ret_status = status;
//  }	
//  exit(ret_status);

void	exec_processes(t_sequential_processes_list *sq_proc_lst)
{
	while (sq_proc_lst) //プロセスのループ
	{
		if (should_exec_builtins(sq_proc_lst->proc)) //ビルトインを実行するかどうか(前後が番兵かi.e.コマンドがFのように単一かどうか)
			exec_builtins(/*t_cmd_list*/);
		else if (fork())
		{
			wait(NULL);
		}
		else
		{
			exec_cmds(/*t_process_list*/); //パイプのwhileループ(列のループ)
		}
		sq_proc_lst = sq_proc_lst->next;
	}
}

#ifdef EXEC_PROCESSES_C

int main(void)
{
	// not test yet
}

#endif
