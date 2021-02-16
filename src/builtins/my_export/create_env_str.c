#include <stdlib.h>
#include "libft.h"
#include "struct/env_list.h"

static int count_bk_slsh_should_insert_into_value(char *value)
{
	int bk_slsh_count;

	bk_slsh_count = 0;
	while (*value)
	{
		if (*value == '\\' || *value == '$' || *value == '\"')
			++bk_slsh_count;
		++value;
	}
	return bk_slsh_count;
}

static char *insert_back_slash(char *value)
{
	int i;
	char *value_inserted_bk_slsh;

	value_inserted_bk_slsh = 
	malloc(sizeof(char) *
	(ft_strlen(value) + count_bk_slsh_should_insert_into_value(value) + 1));	// TODO:エラー処理
	i = 0;
	while (*value)
	{
		if (*value == '\\' || *value == '$' || *value == '\"')
		{
			value_inserted_bk_slsh[i] = '\\';
			++i;
		}
		value_inserted_bk_slsh[i] = *value;
		++i;
		++value;
	}
	value_inserted_bk_slsh[i] = '\0';
	return (value_inserted_bk_slsh);
}

char *create_env_str(t_env_list *env_node)
{
	char	*env_str;
	char	*value_inserted_bk_slsh;
	char	*tmp;

	if (!(env_node->value))
		env_str = ft_strdup(env_node->key);
	else
	{
		env_str = ft_strjoin(env_node->key, "=\"");	// TODO:エラー処理
		if (ft_strchr(env_node->value, '\\') || ft_strchr(env_node->value, '$')
		|| ft_strchr(env_node->value, '\"'))
		{
			value_inserted_bk_slsh = insert_back_slash(env_node->value);
			tmp = ft_strjoin(env_str, value_inserted_bk_slsh);	// TOOD:エラー処理
			free(value_inserted_bk_slsh);
		}
		else
			tmp = ft_strjoin(env_str, env_node->value);	// TODO:エラー処理
		free(env_str);
		env_str = ft_strjoin(tmp, "\"");	// TODO:エラー処理
		free(tmp);
	}
	return (env_str);
}

