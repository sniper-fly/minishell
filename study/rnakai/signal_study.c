#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

void	abrt_handler(int sig)
{
	(void)sig;
	write(1, "hello\n", 6);
}

int main()
{
	// char **argments = (char*[]){
	// 	"wc",
	// 	NULL
	// };
	char **argments = (char*[]){
		"ls",
		NULL
	};
	int status;
	signal(SIGINT, SIG_IGN);
	// signal(SIGINT, abrt_handler);

	// child
	if (fork() == 0)
	{
		// execvp("wc", argments);
		execvp("ls", argments);
		write(1, "world", 5);
	}

	//parent
	else
	{
		wait(&status);
		printf("complete\n");
	}
}