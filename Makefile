CC = CC
FLAGS = -Wall -Wextra -Werror
RM = rm -f
FILES = so_long.c
OBJECT = $(FILES:.c=.o)

NAME = so_long

all:$(NAME)

$(NAME):$(OBJECT)
	$(CC) $(FLAGS) $(OBJECT) - $@

%.o:%.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean: $(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all