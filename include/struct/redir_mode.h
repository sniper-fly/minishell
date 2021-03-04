#ifndef REDIR_MODE_H
# define REDIR_MODE_H

/*
** flags for mode_bit
*/

# define REDIR_BAD_FD	0b10000
# define REDIR_IN		0b01000
# define REDIR_OUT		0b00100
# define REDIR_ERR		0b00010
# define REDIR_APPEND	0b00001

typedef struct		s_redirect
{
	int		mode_bit;
	char	*fd_str;
}					t_redir_mode;

#endif
