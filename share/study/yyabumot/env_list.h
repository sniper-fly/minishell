#ifndef ENV_VAR_H
#define ENV_VAR_H

typedef struct	s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
	struct s_env_list	*prev;
}				t_env_list;

extern t_env_list *env_list;

#endif
