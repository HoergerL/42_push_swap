NAME = push_swap
CC = gcc
CFLAGS = #-Wall -Werror -Wextra
RM = rm -f

LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
FILES = main.c handle_input.c errors.c swap.c push.c rotate.c reverse_rotate.c subsequence.c subsequence_utils.c outsource_elements.c
OBJ = $(FILES:.c=.o)

 BONUS = 
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
	gcc -Wall -Werror -Wextra $(BONUS) -c
	ar rc $(NAME) *.o
