CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = fillit
SRC =	initialisation/new_fillist_elem.c\
	initialisation/extern_file.c\
	initialisation/check_input.c\
	initialisation/load_lst.c\
	initialisation/init_grille.c\
	backtracking/check_tetrimino.c\
	backtracking/set_tetrimino.c\
	backtracking/rm_tetrimino.c\
	backtracking/brute_force.c\
	main.c\

OBJ = $(SRC:.c=.o)
INCLUDE_LIB = libft/includes/


all: $(NAME)

$(NAME): ./libft/libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I $(INCLUDE_LIB) -L libft/ -lft -I ./

./libft/libft.a : 
	make -C libft/ fclean && make -C libft/ && make -C libft/ clean

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE_LIB) -I ./ $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean $(NAME)
