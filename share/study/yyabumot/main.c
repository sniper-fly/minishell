#include "tutorials.h"

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
	// char *line = "ls -l | wc -l";
	// char *line = "du -a | sort -n | wc -l ; ls -l | wc";
	// char *line = "du -a | sort -n | wc -l ; ls -l | wc -l ; echo hello world";
	// char *line = "du -a | sort -n";
	// char *line = "wc < in1.txt < in2.txt > out.txt";
	// char *line = "cat | ls";
	char *line = "cd .. ; ls";
	// char *line = "env ; export foo=foo ; env";
	// char *line = "unset PATH ; env | grep PATH";

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

	// exec commands
	char *builtin_str[] = {"cd", "export", "unset", "exit"};
	int (*builtin_func[])(char **) = {&exec_cd, &exec_export, &exec_unset, &exec_exit};
	for(int i = 0; i < sizeof(builtin_str)/sizeof(char *); ++i){
		if(!ft_strncmp(p_lst->c_lst->arg[0], builtin_str[i], ft_strlen(p_lst->c_lst->arg[0]))){
			builtin_func[i](p_lst->c_lst->arg);
			p_lst = p_lst->next;
			break;
		}
	}
	exec_cmds(p_lst);

/*
	int pid;
	int status;
	char buf[256];

	if((pid = fork())){
		read(0, buf, 256);
	}else{
		exec_cmds(p_lst);
	}
*/
}