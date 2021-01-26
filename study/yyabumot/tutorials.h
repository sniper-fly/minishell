#ifndef TUTORIALS_H
#define TUTORIALS_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

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


int exec_cd(char **arg);
int exec_export(char **arg);
int exec_unset(char **arg);
int exec_exit(char **arg);
void exec_cmds(prcss_lst *p_lst);
//int exec_builtins(char **arg);

#endif