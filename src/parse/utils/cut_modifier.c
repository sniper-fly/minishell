#include "constants.h"
#include "libft.h"
#include "parse.h"

char	*cut_modifier(char *src)
{
	char	*dst;
	int		i_src;
	int		i_dst;

	dst = ft_calloc(sizeof(char*), ft_strlen(src));
	if (dst == NULL)
		return (NULL);
	i_dst = 0;
	i_src = 0;
	while (src[i_src])
	{
		if (src[i_src] == DOUBLE_QUOTE || src[i_src] == SINGLE_QUOTE)
		{
			i_src++;
			continue ;
		}
		else if (src[i_src] == BACK_SLASH)
			i_src++;
		dst[i_dst] = src[i_src];
		i_src++;
		i_dst++;
	}
	return (dst);
}
