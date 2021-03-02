#!/bin/bash

all_test_files="`find ./test/cfiles -type f -name "*.c"` src/main.c"
echo "==================================="

function touch_all() {
	touch $all_test_files
}

function update_each_file() {
	printf "\033[32m%s\033[m\n" "---$1---"
	echo #改行
	touch_all
	make debug ARG=$1
	./minishell > ./test/answer/result/$1 2>&1
	# valgrindの一列目はprocess IDが入ってしまって比較の邪魔なのでawkで消している
	# valgrind --undef-value-errors=no ./minishell 2>&1 |
	# awk -F" " '{$1=""; print}' > ./test/answer/memleak_log/$1
	valgrind ./minishell > ./test/answer/memleak_log/$1 2>&1
	echo "==================================="
}

### 毎回updateしているとテストの意味がなくなるので、一度作ったらコメントアウトする ###

# update_each_file REPLACE_META_WITH_DIVIDER_C
# update_each_file MY_EXECVE_C
# update_each_file FREE_PROCS_C
# update_each_file SHOW_STRING_ARR_C
# update_each_file FT_PERROR_C
# update_each_file CHECK_EXIT_STATUS_OF_MY_EXECVE_C
# update_each_file CONVERT_LINE2TASKS_C
# update_each_file EXEC_CMD_FOR_DEBUG_C

## parse
# update_each_file AUTO_RESIZE_CPY_C
# update_each_file GET_SINGLE_ENV_KEY_C
# update_each_file EXPAND_ENV_VAR_STR_C

## builtins
# update_each_file MY_ECHO_C
# update_each_file MY_EXPORT_C
# update_each_file MY_UNSET_C
# update_each_file MY_ENV_C
# update_each_file MY_PWD_C
# update_each_file MY_EXIT_C
# update_each_file EXEC_BUILTINS_C

# update_each_file DETECT_REDIR_MODE_C
# update_each_file IS_JUDGE_FUNCS_C
# update_each_file FILL_SPACE_C
# update_each_file GET_REDIRECT_FILE_C
# update_each_file OPEN_REDIR_FILE
# update_each_file CUT_MODIFIER_C

# update_each_file PARSE_EACH_TASK_C
# update_each_file IS_VALID_QUOTE_C
# update_each_file IS_VALID_CHAR_CODE_C
# update_each_file IS_VALID_META_AND_REDIRECT_C
