
NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

SRC = ft_ssl.c parser.c fun_md5.c md5_stages.c md5.c

all: $(NAME)

$(NAME):
	@gcc  $(FLAGS) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all