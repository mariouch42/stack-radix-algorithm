NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
       parsing.c \
       parsing_utils.c \
       stack_utils.c \
       sort_utils.c \
       sort_small.c \
       swap.c \
       push.c \
       rotate.c \
       reverse_rotate.c \
       sort_large.c \
       ft_split.c \
       ft_split_utils.c 
       

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re