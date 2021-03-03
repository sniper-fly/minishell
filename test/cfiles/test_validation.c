#ifdef IS_CMD_LINE_TERMINATED_WITH_BKSLSH_C

#include <stdlib.h>
#include "libft.h"
#include "validation.h"
#include "constants.h"
#include "struct/t_bool.h"

static void test_backslash(char *cmd_line)
{
	t_bool ret_bool;

	ret_bool = is_cmd_line_terminated_with_bkslsh(cmd_line);
	if(ret_bool == TRUE)
		ft_putstr_fd("\x1b[31mINVALID\x1b[m", STD_OUT);
	else
		ft_putstr_fd("\x1b[32mVALID\x1b[m", STD_OUT);
	ft_putstr_fd(" : ", STD_OUT);
	ft_putendl_fd(cmd_line, STD_OUT);
}

int main(void)
{
	char *valid_cmds[] =
	{
		"echo \\\\\n",
		"\\\\\n",
	};

	char *invalid_cmds[] =
	{
		"\\\n",
		"\\\\\\\n",
		"\\\\\\\\\\\n",
		"echo \\\n",
		"echo\\a \\\\\\\n",
	};

	ft_putstr_fd("Valid commands ==========\n", STD_OUT);
	for(size_t i = 0; i < sizeof(valid_cmds) / sizeof(char *); ++i)
		test_backslash(valid_cmds[i]);

	ft_putstr_fd("\nInvalid commands ========\n", STD_OUT);
	for(size_t i = 0; i < sizeof(invalid_cmds) / sizeof(char *); ++i)
		test_backslash(invalid_cmds[i]);
}

#endif

#ifdef IS_VALID_QUOTE_C

#include <stdlib.h>
#include "libft.h"
#include "validation.h"
#include "constants.h"
#include "struct/t_bool.h"

static void test_quote(char *cmd_line)
{
	t_bool ret_bool;

	ret_bool = is_valid_quote(cmd_line);
	if(ret_bool == TRUE)
		ft_putstr_fd("\x1b[32mVALID\x1b[m", STD_OUT);
	else
		ft_putstr_fd("\x1b[31mINVALID\x1b[m", STD_OUT);
	ft_putstr_fd(" : ", STD_OUT);
	ft_putendl_fd(cmd_line, STD_OUT);
}

int main(void)
{
	char *valid_cmds[] =
	{
		"echo \"hello\"",
		"echo \'hello\'",
		"echo \"hell\\\"o\"",
		"echo \"\"",
		"echo \"hello\'\'world\""
		"echo \"a\\\"a\" ", //   "a\"a"
		"echo \'a\\\"a\' ", //   'a\"a'
		"echo \'a\\\' ", //   'a\'
		"echo \'a\"a\' ", //   'a"a'
		"echo \"h\'e\"l\'l\"o\'",
		"\"echo\" \"hello\"",
		"  \\\"  ",
		"  \\\'  ",
	};

	char *invalid_cmds[] =
	{
		"echo \"hello",
		"ehco \'hello",
		"ehco \"hello\'",
		"echo \'hello\"",
		"echo \'hell\\\'o\'",
		"echo \"h\'e\"l\'l\"o\"",
		"echo \"\"\"",
		"echo \"\"\"\"\"\"\""
		"echo \'a\\\'a\'", //   'a\'a'
		"echo \'a\\\'\' ", //   'a\''
		"echo \"a",
		"echo \"\\", //この例だとセグフォする可能性がある
	};

	ft_putstr_fd("Valid commands ==========\n", STD_OUT);
	for(size_t i = 0; i < sizeof(valid_cmds) / sizeof(char *); ++i)
		test_quote(valid_cmds[i]);

	ft_putstr_fd("\nInvalid commands ========\n", STD_OUT);
	for(size_t i = 0; i < sizeof(invalid_cmds) / sizeof(char *); ++i)
		test_quote(invalid_cmds[i]);
}

#endif


#ifdef IS_VALID_CHAR_CODE_C

#include "libft.h"
#include "constants.h"
#include "validation.h"

void test_char_code(char *cmd_line, int cmd_num)
{
	t_bool ret_bool;

	ft_putstr_fd("cmd", STD_OUT);
	ft_putnbr_fd(cmd_num, STD_OUT);
	ft_putstr_fd(": ", STD_OUT);
	ret_bool = is_valid_char_code(cmd_line);
	if(ret_bool == TRUE)
		ft_putendl_fd("TRUE", STD_OUT);
}

int main(void)
{
	// 正常なコマンド
	char cmd0[] = "echo hello";

	// 日本語入り
	char cmd1[] = "echo おはよう";

	// 漢字入り
	char cmd2[] = "echo 朝";

	test_char_code(cmd0, 0);
	test_char_code(cmd1, 1);
	test_char_code(cmd2, 2);
}

#endif

#ifdef IS_VALID_META_AND_REDIRECT_C

#include <stdio.h>
#include "libft.h"
#include "constants.h"
#include "validation.h"

void test_valid_meta(char *cmd_line)
{
	t_bool ret_bool;

	ret_bool = is_valid_meta_and_redirect(cmd_line);
	if(ret_bool == TRUE)
		ft_putstr_fd("\x1b[32mVALID\x1b[m", STD_OUT);
	else
		ft_putstr_fd("\x1b[31mINVALID\x1b[m", STD_OUT);
	ft_putstr_fd(" : ", STD_OUT);
	ft_putendl_fd(cmd_line, STD_OUT);
}

int main(void)
{
	// 正常なコマンド
	char *cmds0[] =
	{
	"echo hello | wc",
	"echo hello > a | wc",
	"echo hello >> a | wc",
	"cat < a | wc",
	"cat < a > b | wc",
	"cat > a < b | wc",
	"echo hello > a > b",
	"echo hello < a < b",
	"echo hello > a > b > c >> d < e < f",
	"echo hello > a < b < c > d < e >> f",
	"   ",
	"\t   ",
	"",
	">a"
	};

	// 初手メタ
	char *cmds1[] =
	{
	"| wc",
	"; echo hello",
	"   \t; echo hello"
	};

	// メタ後メタ
	char *cmds2[] =
	{
	"echo hello |  | wc",
	"echo hello | ; ls",
	"echo hello|\t;ls"
	};

	// 対象外のリダイレクト
	char *exeption_redirect = "cat << a";

	// リダイレクト後メタ
	char *cmds3[] =
	{
	"echo hello > |",
	"echo hello < |",
	"<|",
	};

	// リダイレクト後リダイレクト
	char *cmds4[] =
	{
	"echo hello > > a.txt",
	"echo hello < > a.txt",
	"echo hello > < a.txt",
	"echo hello < < a.txt",
	"echo hello > >> a.txt",
	"echo hello < >> a.txt",
	"echo hello >> < a.txt",
	"echo hello << a.txt",
	"echo hello << > a.txt",
	"echo hello > << a.txt",
	"echo hello >> << a.txt",
	"echo hello >> >> a.txt",
	"echo hello << << a.txt"
	};

	// 最後リダイレクト
	char *cmds5[] =
	{
	"echo hello >",
	"echo hello <",
	"echo hello >>",
	"echo hello >> a >",
	"echo hello <                    "
	};

	// cmds0
	ft_putstr_fd("Normal commands ===========================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds0) / sizeof(char *); ++i)
		test_valid_meta(cmds0[i]);


	// cmds1
	ft_putstr_fd("\nStart with meta ============================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds1) / sizeof(char *); ++i)
		test_valid_meta(cmds1[i]);

	// cmds2
	ft_putstr_fd("\nMeta following meta ========================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds2) / sizeof(char *); ++i)
		test_valid_meta(cmds2[i]);

	// cmds3
	ft_putstr_fd("\nMeta following redirect ====================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds3) / sizeof(char *); ++i)
		test_valid_meta(cmds3[i]);

	// 対象外のリダイレクト
	ft_putstr_fd("\nExeption redirect ==========================\n", STD_OUT);
	test_valid_meta(exeption_redirect);

	// cmds4
	ft_putstr_fd("\nRedirect following redirect ================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds4) / sizeof(char *); ++i)
		test_valid_meta(cmds4[i]);

	// cmds5
	ft_putstr_fd("\nEnds with redirect ==========================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds5) / sizeof(char *); ++i)
		test_valid_meta(cmds5[i]);
}

#endif