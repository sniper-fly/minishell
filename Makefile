
# Makefile ver1.3

NAME = minishell
SRCS = $(shell find ./src -type f -name "*.c") \
	$(shell find ./lib -type f -name "*.c")
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include

# make debug ARG=READ_CMD_LINE_C　のようにして使う。
ifdef DEBUG
CFLAGS += -g -fsanitize=address -D DEBUG=1 -D $(ARG)=1
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

-include $(DEPS)

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug:
	make DEBUG=1

run: all
	./minishell

.PHONY: all clean fclean re debug run
