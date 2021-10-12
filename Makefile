NAME = push_swap
NAME_BONUS = checker
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -f

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
FILES = main.c handle_input.c errors.c swap.c push.c rotate.c reverse_rotate.c subsequence.c subsequence_utils.c outsource_elements.c push_back.c push_back_utils.c main_utils.c push_back_utils2.c push_back_utils3.c
BONUS = push_swap_tester.c handle_input.c errors.c swap.c push.c rotate.c reverse_rotate.c subsequence.c subsequence_utils.c outsource_elements.c push_back.c push_back_utils.c main_utils.c push_back_utils2.c push_back_utils3.c

OBJ = $(FILES:.c=.o)
OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -c $(FILES)
	make -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)
clean:
	cd libft && make clean
	rm -f *.o
fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all

bonus:
	$(CC) $(CFLAGS) -c $(BONUS)
	make -C ./libft
	make -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(PRINTF) -o $(NAME_BONUS)
