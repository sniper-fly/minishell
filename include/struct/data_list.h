#ifndef DATA_LIST_H
#define DATA_LIST_H

typedef struct	s_cmd_list
{
	char				*arg;
	struct s_cmd_list	*next;
}				t_cmd_list;

//リストの列
typedef struct	s_process_list
{
	t_cmd_list				*cmd;
	char					*red_in_file_name;
	int						should_append;
	char					*red_out_file_name;
	struct s_process_list	*next;
	struct s_process_list	*prev;
}				t_process_list;

//リストの行
typedef struct	s_sequential_processes_list
{
	t_process_list						*proc;
	struct s_sequential_processes_list	*next;
}				t_sequential_processes_list;

#endif
