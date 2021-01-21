#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t e_flag = 0;
volatile sig_atomic_t quit_flag = 0;

void abrt_handler(int sig);
void	quit_handler(int sig);

int main()
{
	printf("start %s\n", __func__);
	if (signal(SIGINT, abrt_handler) == SIG_ERR)
	{
		exit(1);
	}
	if (signal(SIGQUIT, quit_handler) == SIG_ERR)
	{
		exit(1);
	}

	while (!e_flag)
	{
	}
	while (!quit_flag)
	{
	}

	printf("end %s\n", __func__);

	return 0;
}

void abrt_handler(int sig) {
	(void)sig;
  e_flag = 1;
}

void	quit_handler(int sig) {
	(void)sig;
	quit_flag= 1;
}