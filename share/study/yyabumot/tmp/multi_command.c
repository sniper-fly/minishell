#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./libft/libft.h"

typedef struct cmd_lst{
	char **arg;
	struct cmd_lst *next;
}	cmd_lst;

typedef struct prcss_lst{
	cmd_lst *c_lst;
	struct prcss_lst *next;
}	prcss_lst;

void cmd_lst_add(cmd_lst **c_lst, cmd_lst *c_new)
{
	if(!(*c_lst))
		*c_lst = c_new;
	else{
		c_new->next = *c_lst;
		*c_lst = c_new;
	}
}

void prcss_lst_add(prcss_lst **p_lst, prcss_lst *p_new)
{
	prcss_lst *tmp;

	if(!(*p_lst))
		*p_lst = p_new;
	else{
		tmp = *p_lst;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = p_new;
	}
}

char **make_arg(char *line)
{
	int idx;
	char **tmp;
	char *ptr;

	for(int i = 0; line[i]; ++i){
		if(line[i] == '\''){
			while(line[++i] != '\''){
				if(line[i] == ' ')
					line[i] = 1;
			}
		}
		if(line[i] == '\"'){
			while(line[++i] != '\"'){
				if(line[i] == ' ')
					line[i] = 1;
			}
		}
	}
	tmp = ft_split(line, ' ');
	for(int i = 0; tmp[i]; ++i){
		tmp[i] = ft_strtrim(tmp[i], "\'\"");
		if(ptr = ft_strchr(tmp[i], 1))
			*ptr = ' ';
	}
	return tmp;
}

void exec_pipe(cmd_lst *lst)
{
	int pid;
	int fds[2];
	int status;

	
	if(!(lst->next)){
		execvp(lst->arg[0], lst->arg);
		exit(0);
	}
	pipe(fds);
	if((pid = fork())){
		// parent
		close(fds[1]);
		dup2(fds[0], 0);
		close(fds[0]);
		execvp(lst->arg[0], lst->arg);
		wait(&status);
		exit(0);
	}else{
		// child
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		exec_pipe(lst->next);
		exit(0);
	}
}

void exec_cmd(prcss_lst *p_lst)
{
	int child;
	int status;

	while(p_lst){
		if(child = fork())
			wait(&status);
		else
			exec_pipe(p_lst->c_lst);
		p_lst = p_lst->next;
	}
}

int main(void)
{
//	char *line = "ls -l | wc -l";
//	char *line = "du -a | sort -n | wc -l ; ls -l | wc";
	char *line = "du -a | sort -n | wc -l ; ls -l | wc -l ; echo hello world";
//	char *line = "du -a | sort -n";

	char **split_prcss = ft_split(line, ';');
	char **split_pipe;
	prcss_lst *p_lst = NULL;
	prcss_lst *p_new;
	cmd_lst *c_lst = NULL;
	cmd_lst *c_new;

	for(int i = 0; split_prcss[i]; ++i){
		split_pipe = ft_split(split_prcss[i], '|');
		for(int j = 0; split_pipe[j]; ++j){
			c_new = malloc(sizeof(cmd_lst));
			c_new->arg = make_arg(split_pipe[j]);
			c_new->next = NULL;
			cmd_lst_add(&c_lst, c_new);
		}
		p_new = malloc(sizeof(prcss_lst));
		p_new->c_lst = c_lst;
		p_new->next = NULL;
		prcss_lst_add(&p_lst, p_new);
		c_lst = NULL;
	}

	exec_cmd(p_lst);
}