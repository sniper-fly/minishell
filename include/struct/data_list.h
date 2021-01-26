#ifndef DATA_LIST_H
#define DATA_LIST_H

typedef struct	s_cmd_list
{
	char				*arg;
	struct s_cmd_list	*next;
}				t_cmd_list;

//リストの列
typedef struct	s_list_column
{
	t_cmd_list				*cmd;
	char					*red_in_file_name;
	int						should_append;
	char					*red_out_file_name;
	struct s_list_column	*next;
	struct s_list_column	*prev;
}				t_list_column;

//リストの行
typedef struct	s_list_row
{
	t_list_column		*proc;
	struct s_list_row	*next;
}				t_list_row;

#endif
