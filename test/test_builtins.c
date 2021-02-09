#include "builtins.h"

#ifdef MY_ECHO_C 

int main(void)
{
	char *args[]= {"echo", "hello1", NULL};
	char *args2[] = {"echo", "-nn", NULL};
	char *args3[] = {"echo", "-nnnnnnn", "3", NULL};
	char *args4[] = {"echo", "-nnnnnnn", "4", NULL};
	char *args5[] = {"echo", "-n", "-n", "-n", "5", NULL};
	char *args6[] = {"echo", "-n", "-n", "6", "6", NULL};
	char *args7[] = {"echo", "-n4", NULL};
	char *args8[] = {"echo", "-n!", NULL};
	char *args9[] = {"echo", "-n", NULL};
	char *args10[] = {"echo", "-n", "world10", NULL};
	char *args11[] = {"echo", "-n", "hello11", "world", NULL};

	char *args12[] = {"echo", "hoge", "\\n", NULL};
	char *args13[] = {"echo", "hoge", "fuga", NULL};

	char *args14[] = {"echo", NULL};

	char *args15[] = {"echo", "hello", "-n", NULL};

	my_echo(args);
	my_echo(args2);
	my_echo(args3);
	my_echo(args4);
	my_echo(args5);
	my_echo(args6);
	my_echo(args7);
	my_echo(args8);
	my_echo(args9);
	my_echo(args10);
	my_echo(args11);
	my_echo(args12);
	my_echo(args13);
	my_echo(args14);
	my_echo(args15);
}

#endif
