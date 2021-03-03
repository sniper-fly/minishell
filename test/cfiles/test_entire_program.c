#ifdef TEST_ENTIRE_PROGRAM_C
#include "utils.h"
#include <stdio.h>
#include <signal.h>
#include "constants.h"
#include "exit_status.h"
#include "main.h"
#include "libft.h"
#include <stdlib.h>

#define LINE_LEN 2000

extern volatile sig_atomic_t	g_status;

static void		cut_last_endl(char *line)
{
	char	*endl_ptr;

	endl_ptr = ft_strchr(line, '\n');
	if (endl_ptr)
		*endl_ptr = '\0';
}

static void put_format(char *cmd_line)
{
	static int	line_num = 1;
	char		cmd_buf[LINE_LEN + 10];

	pendl();
	ft_putstr_fd("===================(", STD_OUT);
	ft_putnbr_fd(line_num, STD_OUT);
	ft_putstr_fd(")===================\n", STD_OUT);
	cut_last_endl(cmd_line);
	ft_putstr_fd("[", STD_OUT);
	ft_putstr_fd(cmd_line, STD_OUT);
	ft_putstr_fd("]\n", STD_OUT);

	ft_putendl_fd("--------bash result---------", STD_OUT);
	if (ft_strchr(cmd_line, SINGLE_QUOTE))
		system(cmd_line);
	else
	{
		sprintf(cmd_buf, "bash -c '%s'", cmd_line);
		system(cmd_buf);
	}
	ft_putendl_fd("--------user result---------", STD_OUT);	
	line_num++;
}

int		main(int argc, char **argv, char **envp)
{
	char		*line;
	char		***tasks;
	FILE		*fp = NULL;
	char		cmd_line[LINE_LEN];

	ft_bzero(cmd_line, LINE_LEN);
	fp = fopen("test/entire/testcases.txt", "r");
	if (fp == NULL)
	{
		perror(NULL);
		return (0);
	}

	setup_shell(&line, envp);
	while (fgets(cmd_line, LINE_LEN, fp) != NULL)
	{
		put_format(cmd_line);
		if (is_full_of_space(cmd_line))
			continue ;
		if (!is_valid_command_line(cmd_line)) //lineは再利用するのでfreeしない
		{
			g_status = SYNTAX_ERROR; //exit statusの名前設定NOTE:
			continue ;
		}
		tasks = convert_line2tasks(cmd_line); //TODO:
		exec_tasks(tasks); //失敗したらtasksをfreeし忘れないように
		free_tasks(tasks);
	}
	free(line);
	(void)argc; (void)argv; (void)envp;
}

#endif
