#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`
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
	valgrind ./minishell 2>&1 > ./test/answer/memleak_log/$1
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
