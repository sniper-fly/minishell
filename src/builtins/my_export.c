#include <stdio.h>	//
#include <unistd.h>	//
#include "libft.h"
#include "utils.h"
#include "constants.h"
#include "struct/env_list.h"

t_env_list *g_env_list;

void my_export(char *arg)
{
	t_env_list *env_node;
	t_env_list *new;

	if(!arg){
		env_node = g_env_list->next;
		while(env_node->key){
			ft_putstr_fd(env_node->key, STD_OUT);
			ft_putstr_fd("=", STD_OUT);
			ft_putendl_fd(env_node->value, STD_OUT);
			env_node = env_node->next;
		}
	}else if(ft_strchr(arg, '=')){
		new = make_new_env_node(arg);
		new->next = g_env_list;
		if(!(g_env_list->next)){
			g_env_list->next = new;
			new->prev = g_env_list;
		}else{
			g_env_list->prev->next = new;
			new->prev = g_env_list->prev;
		}
		g_env_list->prev = new;
	}
}

// int main(int argc, char *argv[], char *envp[])
// {
// 	make_env_list(envp);
// 	my_export("foo=foo");
// 	char *cmd[] = {"env", NULL};
// 	execvp(cmd[0], cmd);
// }