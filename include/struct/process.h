#ifndef PROCESS_H
#define PROCESS_H

typedef struct	s_process
{
	char		**cmd;
	char		*red_in_file_name;
	char		*red_out_file_name;
	int			red_out_mode; //APPEND, OVERWRITEフラグで管理する
	int			is_end; //列の最後を表す。列の終わりのみTRUE
}				t_process;

#endif

// "cat aaa | ls -l ; echo hello"
// A | B | C ; D | E ; F

// t_process_list	**list;
// t_process_list	element;
// (list[0][1].cmd)[1] == -l

// A B C
// D E
// F

typedef struct	s_cmd_list
{
	char				*arg;
	struct s_cmd_list	*next;
}				t_cmd_list;

// //リストの列
// typedef struct	s_process_list
// {
// 	t_cmd_list				*cmd;
// 	char					*red_in_file_name;
// 	int						should_append;
// 	char					*red_out_file_name;
// 	struct s_process_list	*next;
// 	struct s_process_list	*prev;
// }				t_process_list;

// //リストの行
// typedef struct	s_sequential_processes_list
// {
// 	t_process_list						*proc;
// 	struct s_sequential_processes_list	*next;
// }				t_sequential_processes_list;