#ifdef CUT_MODIFIER_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parse.h"

void	test_func(char *str, char *expected, int i)
{
	char	*cutted;

	cutted = cut_modifier(str);
	printf("%d:[%s] [%s]\n", i, str, expected);
	if (strcmp(cutted, expected))
		printf("error at %d, output was [%s]\n\n", i, cutted);
	free(cutted);
}

int		main(void)
{
	char*	examples[] = {
		"input",						"expected",
		"aaa",							"aaa",
		"\"aaa\"",						"aaa",
		"bb\"aaa\"bb",					"bbaaabb",
		"'bb''aaa''bb'",				"bbaaabb",
		"'bb\"aaa\"bb'",				"bb\"aaa\"bb",
		"'\\bb\"aaa\"bb\\'",			"\\bb\"aaa\"bb\\",
		"a\"\\\"\\$\\\\\"a",			"a\"$\\a",
		"a\"b\\\"\\$\\\\b\"a",			"ab\"$\\ba",
		"a\" \\a \\$ \\` \\\" \\\\ \\b \"a",	"a \\a $ ` \" \\ \\b a",
		"\\\\\\\\\\\\",					"\\\\\\",
		"'\\\\\\\\\\\\'",				"\\\\\\\\\\\\",
		"\"\\\\\\\\\\\\\"",				"\\\\\\",
		NULL
	};

	for (int i = 0; examples[i]; i += 2)
	{
		test_func(examples[i], examples[i + 1], i / 2);
	}
}

#endif
