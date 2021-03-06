
# Makefile ver2.2

NAME = minishell

CC = gcc
CFLAGS =  -I./include -g -Wall -Wextra -Werror

#SRCS += の形式でディレクトリを追加。コメントアウトで特定ディレクトリ除外可能
SRCS  = $(shell find ./src -maxdepth 1 -type f -name "*.c")
SRCS += $(shell find ./src/builtins -type f -name "*.c")
SRCS += $(shell find ./src/env -type f -name "*.c")
SRCS += $(shell find ./src/utils -type f -name "*.c")
SRCS += $(shell find ./src/execute -type f -name "*.c")
SRCS += $(shell find ./src/parse -type f -name "*.c")
SRCS += $(shell find ./src/validation -type f -name "*.c")
SRCS += $(shell find ./src/main -type f -name "*.c")
SRCS += $(shell find ./src/signal -type f -name "*.c")

# make debug ARG=READ_CMD_LINE_C　のようにして使う。
ifdef DEBUG
SRCS += $(TEST_SRCS)
CFLAGS += -D DEBUG=1 -D $(ARG)=1 
endif

# sanitizeオプションをつけるときは make sanitize=1 などのように定義して使う
ifdef sanitize
CFLAGS += -fsanitize=address
endif

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

TEST_SRCS = $(shell find ./test/cfiles -type f -name "*.c")
TEST_OBJS = $(TEST_SRCS:.c=.o)
TEST_DEPS = $(TEST_OBJS:.o=.d)

LIBFT = ./lib/libft/libft.a
LIBFT_PATH = ./lib/libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS) $(TEST_OBJS) $(TEST_DEPS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

debug:
	make DEBUG=1

run: all
	./minishell

.PHONY: all clean fclean re debug run
