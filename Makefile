
# Makefile ver1.0	

NAME = minishell
SRCS = $(shell find ./src -type f -name "*.c")
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./include

ifdef DEBUG
CFLAGS += -g -fsanitize=address
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
