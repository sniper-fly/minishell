#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`
ESC=$(printf '\033')
echo "==================================="

function touch_all() {
	touch $all_test_files
}


function test_unit() {
	echo "$1"
	echo #改行
	touch_all
	make -s debug ARG=$1

	echo "---output test result---"
	./minishell > ./test/latest/result/$1 2>&1
	diff ./test/latest/result/$1 ./test/answer/result/$1
	if [ $? -eq 0 ] ; then
		printf "\033[32m%s\033[m\n" 'SUCCESS'
	else
		printf "${ESC}[31m%s${ESC}[m\n" 'FAILURE'
	fi

	# echo "---valgrind test---"
	# # valgrindの一列目はprocess IDが入ってしまって比較の邪魔なのでawkで消している
	# valgrind --undef-value-errors=no ./minishell 2>&1 |
	# awk -F" " '{$1=""; print}' > ./test/latest/memleak_log/$1
	# diff ./test/latest/memleak_log/$1 ./test/answer/memleak_log/$1
	# if [ $? -eq 0 ] ; then
	# 	printf "\033[32m%s\033[m\n" 'SUCCESS'
	# else
	# 	printf "${ESC}[31m%s${ESC}[m\n" 'FAILURE'
	# fi
	valgrind ./minishell > ./test/latest/memleak_log/$1 2>&1

	echo "==================================="
}

test_unit REPLACE_META_WITH_DIVIDER_C
test_unit MY_EXECVE_C
test_unit CHECK_EXIT_STATUS_OF_MY_EXECVE_C
test_unit FREE_PROCS_C
test_unit SHOW_STRING_ARR_C
test_unit FT_PERROR_C
test_unit CONVERT_LINE2TASKS_C
test_unit EXEC_CMD_FOR_DEBUG_C

## parse
test_unit AUTO_RESIZE_CPY_C
test_unit GET_SINGLE_ENV_KEY_C
test_unit EXPAND_ENV_VAR_STR_C

## builtins
test_unit MY_ECHO_C
test_unit MY_EXPORT_C
# test_unit MY_CD_C
test_unit MY_UNSET_C
test_unit MY_ENV_C
test_unit MY_PWD_C
test_unit MY_EXIT_C
test_unit EXEC_BUILTINS_C

test_unit DETECT_REDIR_MODE_C
test_unit IS_JUDGE_FUNCS_C
test_unit FILL_SPACE_C
test_unit GET_REDIRECT_FILE_C