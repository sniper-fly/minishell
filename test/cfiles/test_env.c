#include "env_ctrl.h"
#include "struct/env_list.h"

#ifdef SEARCH_ENV_NODE_C

#include "libft.h"
#include "constants.h"

extern t_env_list *g_env_list;

void test_search_env_node(char *key)
{
	t_env_list *search_node;

	search_node = search_env_node(key);
	ft_putstr_fd(key, STD_OUT);
	ft_putstr_fd(" : ", STD_OUT);
	if(search_node == g_env_list)
		ft_putendl_fd("\x1b[31mEnv not found\x1b[m", STD_OUT);
	else
		ft_putendl_fd(search_node->value, STD_OUT);
}

int main(int argc, char *argv[], char *envp[])
{
	char *env_keys[] = 
	{
		"PWD",
		"SHELL",
		"foo"
	};

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);
	for(size_t i = 0; i < sizeof(env_keys) / sizeof(char *); ++i)
		test_search_env_node(env_keys[i]);
}

#endif

#ifdef CREATE_ENV_LIST_C

#include <stdio.h>

extern t_env_list *g_env_list;

int	main(int argc, char *argv[], char *envp[])
{
	t_env_list *env_node;

	argc += 1;
	argv[0][0] = 'a';
	create_env_list(envp);
	env_node = g_env_list->next;
	while(env_node != g_env_list)
	{
		printf("%s=%s\n", env_node->key, env_node->value);
		env_node = env_node->next;
	}
}

#endif


#ifdef 	MAKE_NEW_ENV_NODE_C

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	t_env_list *new;
	char test_env[] = "foo=foo";

	new = make_new_env_node(test_env);
	printf("key:%s\n", new->key);
	printf("value:%s\n", new->value);
	free(new->key);
	free(new->value);
	free(new);
}

#endif