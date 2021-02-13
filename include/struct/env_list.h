#ifndef ENV_LIST_H
#define ENV_LIST_H

typedef struct	s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
	struct s_env_list	*prev;
}				t_env_list;

extern t_env_list *g_env_list;

#endif
