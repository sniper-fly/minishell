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
	"echo hello > a < b < c > d < e >> f"
	};

	// 初手メタ
	char *cmds1[] =
	{
	"| wc",
	"; echo hello"
	};

	// メタ後メタ
	char *cmds2[] =
	{
	"echo hello |  | wc",
	"echo hello | ; ls"
	};

	// 対象外のリダイレクト
	char *exeption_redirect = "cat << a";

	// リダイレクト後メタ
	char *cmds3[] =
	{
	"echo hello > |",
	"echo hello < |"
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
	ft_putstr_fd("\nMeta following redirect ====================\n", STD_OUT);
	for(size_t i = 0; i < sizeof(cmds2) / sizeof(char *); ++i)
		test_valid_meta(cmds2[i]);

	// cmds3
	ft_putstr_fd("\nMeta following meta ========================\n", STD_OUT);
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