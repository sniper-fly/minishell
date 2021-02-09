#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`
ESC=$(printf '\033')

function touch_all() {
	touch $all_test_files
}

function test_unit() {
	echo "$1"
	touch_all
	make -s debug ARG=$1

	echo "---output test result---"
	diff <(./minishell 2>&1) ./test/result/$1
	if [ $? -eq 0 ] ; then
		printf "\033[32m%s\033[m\n" 'SUCCESS'
	else
		printf "${ESC}[31m%s${ESC}[m\n" 'FAILURE'
	fi

	echo "---valgrind test---"
	# valgrindの一列目はprocess IDが入ってしまって比較の邪魔なのでawkで消している
	diff <(valgrind ./minishell 2>&1 | awk -F" " '{$1=""; print}') ./test/memleak_log/$1
	if [ $? -eq 0 ] ; then
		printf "\033[32m%s\033[m\n" 'SUCCESS'
	else
		printf "${ESC}[31m%s${ESC}[m\n" 'FAILURE'
	fi

	echo "==================================="
}

test_unit REPLACE_META_WITH_DIVIDER_C
test_unit MY_EXECVE_C
test_unit FREE_PROCS_C