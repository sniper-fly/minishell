#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`

function touch_all() {
	touch $all_test_files
}

function test_unit() {
	echo $1
	touch_all
	make -s debug ARG=$1
	diff <(./minishell 2>&1) ./test/result/$1
}

test_unit REPLACE_META_WITH_DIVIDER_C
test_unit MY_EXECVE_C
