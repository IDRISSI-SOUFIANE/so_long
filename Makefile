CC = CC
FLAGS = -Wall -Wextra -Werror -g
RM = rm -f
FILES = so_long.c ft_split.c get_next_line.c get_next_line_utils.c libft_1.c
OBJECT = $(FILES:.c=.o)

NAME = so_long

all:$(NAME)

$(NAME):$(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) -o $@

%.o:%.c so_long.h mab.ber
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all