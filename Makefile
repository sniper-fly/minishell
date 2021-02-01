
# Makefile ver2.0

NAME = minishell

#SRCS += の形式でディレクトリを追加。コメントアウトで特定ディレクトリ除外可能
SRCS  = $(shell find ./src -maxdepth 1 -type f -name "*.c")
SRCS += $(shell find ./src/builtins -type f -name "*.c")
SRCS += $(shell find ./src/env -type f -name "*.c")
SRCS += $(shell find ./src/utils -type f -name "*.c")
# SRCS += $(shell find ./src/exec_cmd -type f -name "*.c")
# SRCS += $(shell find ./src/parse -type f -name "*.c")

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

LIBFT = ./lib/libft/libft.a
LIBFT_PATH = ./lib/libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include -g

# make debug ARG=READ_CMD_LINE_C　のようにして使う。
ifdef DEBUG
CFLAGS += -D DEBUG=1 -D $(ARG)=1 #-fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re: fclean all

debug:
	make DEBUG=1

run: all
	./minishell

.PHONY: all clean fclean re debug run
