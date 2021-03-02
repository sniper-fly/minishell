#include "exit_status.h"
#include "setup_signal.h"
#include <signal.h>
#include "utils.h"
#include "constants.h"
#include "libft.h"
#include "main.h"

extern volatile sig_atomic_t	g_status;
extern volatile sig_atomic_t	g_is_reading_cmd_line;

static void	interrupt_handler(int sig)
{
	pendl();
	if (g_is_reading_cmd_line)
	{
		print_prompt();
		g_status = STAT_INTERRUPTION;
	}
	(void)sig;
}

static void	quit_handler(int sig)
{
	if (g_is_reading_cmd_line)
	{
		ft_putstr_fd("\b\b  \b\b", STD_OUT);
	}
	else
	{
		ft_putstr_fd("Quit\n", STD_OUT);
	}
	(void)sig;
}

void		setup_signal(void)
{
	signal(SIGINT, interrupt_handler);
	signal(SIGQUIT, quit_handler);
}
