
NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

SRC = ft_ssl.c parser.c fun_md5.c md5_stages.c md5.c sha.c sha_init.c fun_sha.c ft_sha256.c ft_sha512.c put_hash.c

all: $(NAME)

$(NAME):
	@gcc  $(FLAGS) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all