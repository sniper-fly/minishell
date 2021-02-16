#include "libft.h"
#include "struct/t_bool.h"

t_bool	is_valid_env_key(char *key)
{
	if (!ft_strlen(key))
		return (FALSE);
	if ('0' <= *key && *key <= '9')
		return (FALSE);
	while (*key)
	{
		if(!ft_isalnum(*key) && *key != '_')
			return FALSE;
		++key;
	}
	return (TRUE);
}

