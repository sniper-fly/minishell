#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`

function touch_all() {
	touch $all_test_files
}

function update_each_file() {
	touch_all
	make debug ARG=$1
	./minishell > ./test/result/$1 2>&1
}

update_each_file REPLACE_META_WITH_DIVIDER_C
update_each_file MY_EXECVE_C
update_each_file CHECK_EXIT_STATUS_OF_MY_EXECVE_C
