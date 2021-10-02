CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf_utils.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c put_ptr.c puthex.c putunsigndec.c

LIBFT_PATH = ../libft/

MAKE = make

all: sub_libft $(NAME)


$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar -rcs $(NAME) *.o $(LIBFT_PATH)*.o

sub_libft:
	$(MAKE) LIBFT.a -C $(LIBFT_PATH)

clean:
	rm -f *.out
	rm -f *.o
	$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all