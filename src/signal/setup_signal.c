#include "exit_status.h"
#include "setup_signal.h"
#include <signal.h>
#include "utils.h"
#include "constants.h"
#include "libft.h"
#include "main.h"

extern int g_status;

static void	interrupt_handler(int sig)
{
	(void)sig;
	g_status = STAT_INTERRUPTION;
	pendl();
	print_prompt();
}

static void	quit_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\b", STD_OUT);
}

void		setup_signal(void)
{
	signal(SIGINT, interrupt_handler);
	signal(SIGQUIT, quit_handler);
}
