SRC = ./get_next_line.c \
	 ./get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wextra -Werror -Wall

NAME =	libft.a

$(NAME): $(OBJ)
		 ar crs $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

exec: all
	 gcc test/main.c get_next_line.h get_next_line.c get_next_line_utils.c -L. -lft -lbsd -o test/exec
	 ./test/exec $(a)
