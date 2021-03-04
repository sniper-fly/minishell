#include "utils.h"
#include "constants.h"

void		skip_space_idx(char *str, int *i)
{
	while (ft_isspace(str[*i]))
	{
		(*i)++;
	}
}

void		skip_until_end_single_quote(char *line, int *idx)
{
	(*idx)++;
	while (line[*idx] != SINGLE_QUOTE && line[*idx] != '\0')
		(*idx)++;
	(*idx)++;
}

void		skip_until_end_double_quote(char *line, int *idx)
{
	(*idx)++;
	while (1)
	{
		if (line[*idx] == BACK_SLASH)
		{
			(*idx) += 2;
			continue ;
		}
		if (line[*idx] == DOUBLE_QUOTE || line[*idx] == '\0')
			break ;
		(*idx)++;
	}
	(*idx)++;
}

void		skip_escape_seq(char *str, int *i)
{
	if (str[*i] == SINGLE_QUOTE)
		skip_until_end_single_quote(str, i);
	else if (str[*i] == DOUBLE_QUOTE)
		skip_until_end_double_quote(str, i);
	else if (str[*i] == BACK_SLASH)
		(*i) += 2;
}
