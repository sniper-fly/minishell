#ifndef REDIRECT_H
# define REDIRECT_H

/*
** mode_bitで使うbitフラグ
*/

# define REDIR_BAD_FD	0b10000
# define REDIR_IN		0b01000
# define REDIR_OUT		0b00100
# define REDIR_ERR		0b00010
# define REDIR_APPEND	0b00001

typedef struct		s_redirect
{
	int		mode_bit;
	char	*fd_str; 			//for error msg
}					t_redir_mode;

#endif
