SRCS	=	a_to_b.c				\
			b_to_a.c				\
			build_stack.c			\
			errors.c				\
			ft_split.c				\
			main.c					\
			reverse_rotations.c		\
			rotations.c				\
			sort_stacks.c			\
			stack_tools.c			\
			swap_and_sort_three.c	\
			push_ops.c				\
			ft_substr.c				\
			ft_atoi.c				\

OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror
CC 		= 	cc

NAME	=	push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re