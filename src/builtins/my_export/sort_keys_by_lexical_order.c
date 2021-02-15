#include <stdlib.h>
#include "utils.h"
#include "libft.h"

static int	comapre_keys(char *env1, char *env2)
{
	int cmp_result;
	char *env1_key;
	char *env2_key;
	char *env1_eq_ptr;
	char *env2_eq_ptr;

	if(!(env1_eq_ptr = ft_strchr(env1, '=')))
		env1_eq_ptr = env1 + ft_strlen(env1);
	if(!(env2_eq_ptr = ft_strchr(env2, '=')))
		env2_eq_ptr = env2 + ft_strlen(env2);
	env1_key = ft_substr(env1, 0, (size_t)(env1_eq_ptr - env1));	// note:エラー処理
	env2_key = ft_substr(env2, 0, (size_t)(env2_eq_ptr - env2));	// note:エラー処理
	cmp_result = ft_strcmp(env1_key, env2_key);
	free(env1_key);
	free(env2_key);
	return (cmp_result);
}

// keyを辞書順でソート
void			sort_keys_by_lexical_order(char **env_str_arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (env_str_arr[i])
	{
		j = 1;
		while (env_str_arr[j])
		{
			if (0 < comapre_keys(env_str_arr[j - 1], env_str_arr[j]))
			{
				tmp = env_str_arr[j - 1];
				env_str_arr[j - 1] = env_str_arr[j];
				env_str_arr[j] = tmp;
			}
			++j;
		}
		++i;
	}
}