#include "process.h"

//!!!現状コンパイルできません。!!!大枠を示したただの参考資料です。

void	exec_cmd()
{
	while () //行のループ
	{
		if () //ビルトインを実行するかどうか(前後が番兵かi.e.コマンドがFのように単一かどうか)
			exec_builtins(/*t_cmd_list*/)
		else if (fork())
		{
			wait()
		}
		else
		{
			exec_pipes(/*t_process_list*/); //パイプのwhileループ(列のループ)
		}
	}
}

void	exec_pipes()
{
	//並列にforkする
	// forkしたプロセスの中でまずビルトインかどうか調べる
	//ビルトインリストになければmy_execve(t_cmd_list)

	// waitpid()
	// for wait()
}

/////  exec_pipesで、どうやって最後に終了したプロセスの終了ステータスを取得するか
//  for(i = 0; i < cmd_len; i++)
//  {
//         wait(&status);
// 		if (status != 0)
// 			ret_status = status;
//  }	
//  exit(ret_status);
