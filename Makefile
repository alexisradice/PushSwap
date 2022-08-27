NAME = push_swap
NAME_BONUS = checker

SRCS_FILES =	push_swap.c \
				costs.c \
				init.c \
				movements_reverse_rotate.c \
				movements_rotate.c \
				positions.c \
				push.c \
				reverse_rotate.c \
				rotate.c \
				sorting.c \
				swap.c \
				target_positions.c \
				utils_stack.c \
				utils.c \
				parsing.c \

SRCS_FILES_BONUS =	push_swap_bonus.c \
					costs_bonus.c \
					init_bonus.c \
					movements_reverse_rotate_bonus.c \
					movements_rotate_bonus.c \
					positions_bonus.c \
					push_bonus.c \
					reverse_rotate_bonus.c \
					rotate_bonus.c \
					sorting_bonus.c \
					swap_bonus.c \
					target_positions_bonus.c \
					utils_stack_bonus.c \
					utils_bonus.c \
					parsing_bonus.c \
					checker.c \

SRCS_PATH = src/
SRCS_PATH_BONUS = bonus/

SRCS =			$(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_BONUS =	$(addprefix $(SRCS_PATH_BONUS), $(SRCS_FILES_BONUS))

AR = ar
CC = gcc
RM = rm -f

ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -g

INCL = -I./includes -I./libft/includes
LIBFT_PATH = libft/
LIBFT = libft/libft.a

OBJS= $(SRCS:%.c=%.o)
OBJS_BONUS= $(SRCS_BONUS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -o $@ -c $<

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	
$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

$(LIBFT):
	$(MAKE) -C libft all

clean:
	$(RM) $(OBJS)

clean_bonus:
	$(RM) $(OBJS_BONUS)

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

fclean_bonus:	clean_bonus
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME_BONUS)
	
re:	fclean all

re_bonus:	fclean_bonus bonus

.PHONY:	all bonus clean fclean re