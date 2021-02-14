#include <stdlib.h>
#include "libft.h"

static size_t	comapre_key_len(char *env1, char *env2)
{
	size_t	env1_key_len;
	size_t	env2_key_len;

	env1_key_len = (ft_strchr(env1, '=') - env1)/sizeof(char);
	env2_key_len = (ft_strchr(env2, '=') - env2)/sizeof(char);
	return (env1_key_len > env2_key_len ? env1_key_len : env2_key_len);
}

// keyを辞書順でソート
void			sort_keys_by_lexical_order(char **env_str_arr)
{
	int		i;
	int		j;
	char	*tmp;
	size_t	comp_len;	

	i = 1;
	while (env_str_arr[i])
	{
		j = 1;
		while (env_str_arr[j])
		{
			comp_len = comapre_key_len(env_str_arr[j-1], env_str_arr[j]);
			if (0 < ft_strncmp(env_str_arr[j-1], env_str_arr[j], comp_len))
			{
				tmp = env_str_arr[j-1];
				env_str_arr[j-1] = env_str_arr[j];
				env_str_arr[j] = tmp;
			}
			++j;
		}
		++i;
	}
}
