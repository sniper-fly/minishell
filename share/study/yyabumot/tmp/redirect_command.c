#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "./libft/libft.h"

typedef struct cmd_lst{
	char **arg;
	char *in;
	char *out;
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
	// tmp = ft_split(line, ' ');
	// for(int i = 0; tmp[i]; ++i){
	// 	tmp[i] = ft_strtrim(tmp[i], "\'\"");
	// 	printf("%s#", tmp[i]);
	// }
	// printf("\n");
	// return tmp;
}

// A | B | C ; D | E > a ; F | G | H

/*
while(*lst){
	if(redirect){
		fd = open();
		dup2(1, fd);
		close(1)
	}
	exec_cmd();
	open(stdout)
	lst = lst->next;
}
*/

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
			fd = open(lst->out, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU, S_IRWXG, S_IRWXO);
			dup2(fd, 1);
			close(fd);
		}
		execvp(lst->arg[0], lst->arg);
		exit(0);
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
			fd = open(lst->out, O_TRUNC | O_CREAT | O_WRONLY, S_IRWXU, S_IRWXG, S_IRWXO);
			dup2(fd, 1);
			close(fd);
		}
		execvp(lst->arg[0], lst->arg);
		wait(&status);
		exit(0);
	}else{
		// child
		close(fds[0]);
		dup2(fds[1], 1);
		close(fds[1]);
		exec_pipes(lst->next);
		exit(0);
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

void check_redirects(char *line, cmd_lst *lst)
{
	int fd;
	char *ptr;
	char *tmp = ft_strdup(line);
	char **split_space = ft_split(tmp, ' ');

	lst->in = NULL;
	lst->out = NULL;
	for(int i = 0; split_space[i]; ++i){
		if(!ft_strncmp(split_space[i], "<", ft_strlen(split_space[i]))){
			// stdin
			if((ptr = ft_strchr(line, '<')))
				*ptr = '\0';
			++i;
			free(lst->in);
			lst->in = ft_strdup(split_space[i]);
		}else if(!ft_strncmp(split_space[i], ">", ft_strlen(split_space[i]))){
			// stdout
			if((ptr = ft_strchr(line, '>')))
				*ptr = '\0';
			++i;
			fd = open(split_space[i], O_CREAT, S_IRUSR | S_IWUSR);
			close(fd);
			free(lst->out);
			lst->out = ft_strdup(split_space[i]);
		}
	}
}

int main(void)
{
	// test commands
//	char *line = "ls -l | wc -l";
//	char *line = "du -a | sort -n | wc -l ; ls -l | wc";
//	char *line = "du -a | sort -n | wc -l ; ls -l | wc -l ; echo hello world";
//	char *line = "du -a | sort -n";
	char *line = "wc < in1.txt < in2.txt | wc";
//	char *line = "env ; export foo=foo ; env";
//	char *line = "unset PATH ; env | grep PATH";

	char **split_prcss = ft_split(line, ';');
	char **split_pipe;
	prcss_lst *p_lst = NULL;
	prcss_lst *p_new;
	cmd_lst *c_lst = NULL;
	cmd_lst *c_new;

	// make list
	for(int i = 0; split_prcss[i]; ++i){
		split_pipe = ft_split(split_prcss[i], '|');
		for(int j = 0; split_pipe[j]; ++j){
			c_new = malloc(sizeof(cmd_lst));
			check_redirects(split_pipe[j], c_new);
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
//	printf("%s\n", p_lst->c_lst->out);

	// exec commands
	exec_cmds(p_lst);
}