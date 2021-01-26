#ifndef ENV_VAR_H
#define ENV_VAR_H

typedef struct	s_env_list
{
	char				*key;
	char				*value;
	sturct s_env_list	*next;
	sturct s_env_list	*prev;
}				t_env_list;

#endif
