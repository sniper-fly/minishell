NAME = testshell
SRCS = main.c builtins.c exec_cmd.c
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
CC = gcc

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all