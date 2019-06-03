
NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC = ft_ssl.c parser.c fun_md5.c md5_stages.c md5.c sha.c fun_sha.c fun_sha512.c

all: $(NAME)

$(NAME):
	@gcc  $(FLAGS) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all