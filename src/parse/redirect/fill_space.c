#include "struct/redir_mode.h"
#include "libft.h"
#include "parse.h"
#include "utils.h"

void		fill_space(
	char *str_proc, int i, t_redir_mode *redir_mode, char *raw_redir)
{
	int		times;

	times = 0;
	if (redir_mode->fd_str)
	{
		i -= 1;
		times++;
	}
	times += (redir_mode->mode_bit & REDIR_APPEND) ? 2 : 1;
	while (times > 0)
	{
		str_proc[i] = ' ';
		i++;
		times--;
	}
	skip_space_idx(str_proc, &i);
	times = ft_strlen(raw_redir);
	while (times > 0)
	{
		str_proc[i] = ' ';
		i++;
		times--;
	}
}
