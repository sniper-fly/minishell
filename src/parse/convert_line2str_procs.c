#include "constants.h"
#include "libft.h"
#include "struct/process.h"
#include <stdlib.h>
#include "utils.h"
#include "parse.h"

static void		cut_last_endl(char *line)
{
	char	*endl_ptr;

	endl_ptr = ft_strchr(line, '\n');
	if (endl_ptr)
		*endl_ptr = '\0';
}

char		***convert_line2str_procs(char *line)
{
	char		**semicolon_splitted;
	char		**pipe_spilitted;
	char		***str_procs;
	int			i;

	cut_last_endl(line);
	replace_meta_with_divider(line, ';');
	semicolon_splitted = ft_split(line, DIVIDER); //should free TODO: error処理
	//ここでプロセス行数がわかるので、行数分+1 malloc
	str_procs = (char***)ft_calloc(sizeof(char**),
		(count_string_arr_row(semicolon_splitted) + 1)); //TODO:error処理
	i = 0;
	while (semicolon_splitted[i])
	{
		replace_meta_with_divider(semicolon_splitted[i], '|');
		pipe_spilitted = ft_split(semicolon_splitted[i], DIVIDER); //TODO:error処理
		str_procs[i] = pipe_spilitted;
		i++;
	}
	free_string_arr(semicolon_splitted);
	return (str_procs);
}


#ifdef CONVERT_LINE2STR_PROCS_C

//TODO:メモリリーク解消
#include <stdio.h>
#include "debug.h"

static void	p_test(char *line, int i)
{
	char		***str_procs;

	str_procs = convert_line2str_procs(line);
	printf("line%d\n", i);
	show_str_procs(str_procs);
	printf("=======================\n");
}

int		main(void)
{
	char		line0[] = "cmd | cmd1 | cmd 2 ; echo | echo ; hello";
	char		line1[] = "cmd \";\" \"|\"| cmd1 \";\" | ";
	char		line2[] = "cmd \\; aaa; bbb \\|\\; | cc; a";
	char		line3[] = "cmd ';;' aa | cmd1 '|''|' | cmd 2 'a;' ; echo | echo ; hello";

	p_test(line0, 0);
	p_test(line1, 1);
	p_test(line2, 2);
	p_test(line3, 3);
}

#endif
