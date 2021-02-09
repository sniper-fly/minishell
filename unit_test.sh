#!/bin/bash

all_test_files=`find ./test/cfiles -type f -name "*.c"`

function touch_all() {
	touch $all_test_files
}

# function test_unit(filename) {
# 	make debug ARG=filename
# 	./minishell >filename
# 	diff 
# }

touch_all
make -s debug ARG=REPLACE_META_WITH_DIVIDER_C
diff <(./minishell) ./test/result/REPLACE_META_WITH_DIVIDER_C

