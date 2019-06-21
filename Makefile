
NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

SRC = ft_ssl.c parser.c fun_md5.c md5_stages.c md5.c sha.c sha_init.c fun_sha.c ft_sha256.c ft_sha512.c put_hash.c

all: $(NAME)

$(NAME):
	@make -C ft_printf
	@gcc  $(FLAGS) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	@make -C ft_printf/ clean
	@rm -f $(SRC:.c=.o)

fclean: clean
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean all