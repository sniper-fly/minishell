#include "tutorials.h"

void exec_pipes(cmd_lst *lst)
{
	int fd;
	int pid;
	int fds[2];
	int status;

	if(!(lst->next)){
		// redirect
		if(lst->in){
			fd = open(lst->in, O_RDONLY);
			dup2(fd, 0);
			close(fd);
		}
		if(lst->out){
			fd = open(lst->out, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU);
			dup2(fd, 1);
			close(fd);
		}
		execvp(lst->arg[0], lst->arg);
		// exit(0);
	}
	pipe(fds);
	if((pid = fork())){
		// parent
		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);
		// redirect
		if(lst->in){
			fd = open(lst->in, O_RDONLY);
			dup2(fd, 0);
			close(fd);
		}
		if(lst->out){
			fd = open(lst->out, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU);
			dup2(fd, 1);
			close(fd);
		}
		// wait(&status);	// wait不要？
		execvp(lst->arg[0], lst->arg);
		// exit(0);
	}else{
		// child
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		exec_pipes(lst->next);
		// exit(0);
	}
}

void exec_cmds(prcss_lst *p_lst)
{
	int child;
	int status;

	while(p_lst){
		// if(builtin)
		// 	builtin("export");
		if(child = fork())
			wait(&status);
		else
			exec_pipes(p_lst->c_lst);
		p_lst = p_lst->next;
	}
}
