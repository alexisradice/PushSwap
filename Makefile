NAME = push_swap

SRCS_FILES = push_swap.c
SRCS_PATH = src/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

AR = ar
CC = gcc
RM = rm -f

ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

INCL = -I./includes -I./libft/includes
LIBFT_PATH = libft/
LIBFT = libft/libft.a

OBJS= $(SRCS:%.c=%.o)
%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft all

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	
re:	fclean all

.PHONY:	all clean fclean re