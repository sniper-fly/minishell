#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`

function touch_all() {
	touch $all_test_files
}

touch_all
make debug ARG=REPLACE_META_WITH_DIVIDER_C
./minishell > ./test/result/REPLACE_META_WITH_DIVIDER_C 2>&1
