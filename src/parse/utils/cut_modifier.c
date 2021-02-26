#include "utils.h"
#include "constants.h"
#include "libft.h"
#include "parse.h"

static void	cpy_around_back_slash(char *dst, int *i_d, char *src, int *i_s)
{
	(*i_s)++;
	dst[*i_d] = src[*i_s];
	(*i_d)++;
	(*i_s)++;
}

static void	cpy_inside_double_quote(char *dst, int *i_d, char *src, int *i_s)
{
	(*i_s)++;
	while (src[*i_s] != DOUBLE_QUOTE)
	{
		if (src[*i_s] == BACK_SLASH &&
			(src[*i_s + 1] == BACK_SLASH || src[*i_s + 1] == '$' ||
			src[*i_s + 1] == DOUBLE_QUOTE || src[*i_s + 1] == '`'))
		{
			cpy_around_back_slash(dst, i_d, src, i_s);
			continue ;
		}
		dst[*i_d] = src[*i_s];
		(*i_d)++;
		(*i_s)++;
	}
	(*i_s)++;
}

static void	cpy_inside_single_quote(char *dst, int *i_d, char *src, int *i_s)
{
	(*i_s)++;
	while (src[*i_s] != SINGLE_QUOTE)
	{
		dst[*i_d] = src[*i_s];
		(*i_d)++;
		(*i_s)++;
	}
	(*i_s)++;
}

static void	cpy_with_ignoring_escapes(char *dst, int *i_d, char *src, int *i_s)
{
	if (src[*i_s] == DOUBLE_QUOTE)
	{
		cpy_inside_double_quote(dst, i_d, src, i_s);
	}
	else if (src[*i_s] == SINGLE_QUOTE)
	{
		cpy_inside_single_quote(dst, i_d, src, i_s);
	}
	else if (src[*i_s] == BACK_SLASH)
	{
		cpy_around_back_slash(dst, i_d, src, i_s);
	}
}

char		*cut_modifier(char *src)
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
		if (is_escape(src[i_src]))
		{
			cpy_with_ignoring_escapes(dst, &i_dst, src, &i_src);
			continue ;
		}
		dst[i_dst] = src[i_src];
		i_src++;
		i_dst++;
	}
	return (dst);
}
