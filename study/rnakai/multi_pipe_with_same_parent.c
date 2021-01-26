#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

// just count number of commands
int count(char ***cmd)
{
	int i;
	i = 0;
	while (cmd[i])
		i++;
	return i;
}

void pipeline(char ***cmd)
{
	int		i, j = 0;
	pid_t	pid;
	int		cmd_len = count(cmd);
	int		fd[2*cmd_len];

	// pipe(2) for cmd_len times
	for(i = 0; i < cmd_len; i++){
			pipe(fd + i*2);
    }
	while (*cmd != NULL) {

		pid = fork();
		if (pid == 0) {
			// if there is next
			if (*(cmd + 1) != NULL) {
				dup2(fd[j + 1], 1);
			}
			// if there is previous
			if (j != 0) {
				dup2(fd[j - 2], 0);
			}

			for(i = 0; i < 2 * cmd_len; i++){
                close(fd[i]);
            }

			execvp((*cmd)[0], *cmd);
		}

		// no wait in each process, 
		// because I want children to exec without waiting for each other
		// as bash does.
		cmd++;
		j += 2;
	}
	// close fds in parent process
	for(i = 0; i < 2 * cmd_len; i++){
        close(fd[i]);
    }
	// wait for children 
    for(i = 0; i < cmd_len; i++)
        wait(NULL);
}

int
main(int argc, char *argv[])
{
	char *ls[] = {"ls", NULL};
	// char *rev[] = {"rev", NULL};
	// char *nl[] = {"nl", NULL};
	char *cat[] = {"cat", NULL};
	// char *wc[] = {"wc", "-c", NULL};
	// char *head[] = {"head", "-c", "1000", NULL};
	// char *time[] = {"time", "-p", "sleep", "3", NULL};
	// char *echo[] = {"echo", "toto", NULL};
	(void)argc; (void)argv;

	char **cmd[] = {cat, ls, NULL};

	pipeline(cmd);
	return (0);
}