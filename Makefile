NAME = so_long
SRC = srcs/main.c srcs/get_next_line.c srcs/libft0.c srcs/libft1.c srcs/ft_split.c srcs/check_map.c srcs/ft_itoa.c srcs/ft_initialize.c \
	  srcs/ft_initialize2.c srcs/clean_memory.c srcs/ft_draw.c srcs/ft_mange.c srcs/clean_memory2.c  srcs/ft_initialize3.c srcs/trash_functioms.c

OBJ = $(SRC:.c=.o)
all: $(NAME)

CFLAGS = -g 


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ)  -L./includes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -L./includes -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -rf $(OBJ)

# NAME = so_long
# SRC = hh.c  srcs/main.c srcs/get_next_line.c srcs/libft0.c srcs/libft1.c srcs/ft_split.c srcs/check_map.c

# OBJ = $(SRC:.c=.o)
# all: $(NAME)

# CFLAGS = -g -O3

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ)  -L./includes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -L./includes -I/usr/include -Imlx_linux -O3 -c $< -o $@

# clean :
# 	rm -rf $(OBJ)