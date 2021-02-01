#include <unistd.h>
#include "constants.h"
#include <stdlib.h>
#include "libft.h"
#include "read_cmd_line.h"
#include "utils.h"

static t_bool	is_there_endl(char *line)
{
	if (ft_strchr(line, '\n'))
		return (TRUE);
	return (FALSE);
}

static int		read_cmd_line_recursive(char *line, int size_has_read)
{
	int		actual_read_size;

	actual_read_size =
		read(STD_IN, &line[size_has_read], ARG_MAX - size_has_read);
	if (actual_read_size == ERROR)
	{
		ft_perror("minishell");
		return (ERROR);
	}
	else if (actual_read_size == ARG_MAX - size_has_read)
	{
		ft_putstr_fd(
			"minishell: Input reached maximum size(ARG_MAX)\n", STD_ERR);
		return (ERROR);
	}
	//もし改行が含まれてなかったら、つまりctrl-Dが入力されたら
	if (!is_there_endl(line))
	{
		read_cmd_line_recursive(line, ft_strlen(line));
	}
	return (0);
}

int		read_cmd_line(char *line)
{
	int		actual_read_size;

	ft_bzero(line, ARG_MAX + 1);
	actual_read_size = read(STD_IN, line, ARG_MAX);
	if (line[0] == '\0')
		exit(1);		//TODO: exitコードは最後のコマンドの終了値、つまり$?が入る
	else if (actual_read_size == ERROR)
	{
		ft_perror("minishell");
		return (ERROR);
	}
	else if (actual_read_size == ARG_MAX)
	{
		// dump_remained_input(); //エラー処理必要なし //REVIEW: 余裕があれば対応
		//余分に読んでいる部分を吸収する
		ft_putstr_fd(
			"minishell: Input reached maximum size(ARG_MAX)\n", STD_ERR);
		return (ERROR);
	}
	//もし改行が含まれてなかったら、つまりctrl-Dが入力されたら
	if (!is_there_endl(line))
	{
		read_cmd_line_recursive(line, ft_strlen(line));
	}
	return (0);
}

#ifdef READ_CMD_LINE_C

int main(void)
{
	char line[ARG_MAX + 1];
	read_cmd_line(line);
	ft_putstr_fd(line, STD_OUT);
}

#endif
