NAME = so_long
SRC = srcs/main.c srcs/get_next_line.c srcs/libft0.c srcs/libft1.c srcs/ft_split.c srcs/check_map.c srcs/ft_itoa.c srcs/ft_initialize.c \
	  srcs/ft_initialize2.c srcs/clean_memory.c srcs/ft_draw.c srcs/ft_mange.c srcs/clean_memory2.c  srcs/ft_initialize3.c srcs/trash_functioms.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -L./includes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -L./includes -I/usr/include -Imlx_linux  -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re