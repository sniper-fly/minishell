#include "struct/redir_mode.h"
#include "parse.h"
#include "libft.h"

int	count_redir_len(char *str_proc, int i, int mode_bit, char *raw_redir_file)
{
	int		start;

	start = i;
	i += (mode_bit & REDIR_APPEND) ? 2 : 1;
	skip_space_idx(str_proc, &i);
	i += ft_strlen(raw_redir_file);
	return (i - start);
}
