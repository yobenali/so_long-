NAME = so_long
B_NAME = so_long_bonus
SRC = gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	src/check_map.c \
	src/ft_split.c \
	src/ft_strlcpy.c \
	src/ft_strncmp.c \
	src/render.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_utils.c \
	so_long.c \

B_SRCS = gnl_bonus/get_next_line_bonus.c \
	gnl_bonus/get_next_line_utils_bonus.c \
	src_bonus/check_map_bonus.c \
	src_bonus/ft_split_bonus.c \
	src_bonus/ft_strlcpy_bonus.c \
	src_bonus/ft_strncmp_bonus.c \
	src_bonus/ft_itoa_bonus.c \
	src_bonus/render_bonus.c \
	ft_printf_bonus/ft_printf_bonus.c \
	ft_printf_bonus/ft_utils_bonus.c \
	so_long_bonus.c \

CC = gcc
FLAGS = -Wall -Wextra -Werror
MLX = -Imlx -lmlx -framework OpenGl -framework Appkit
$(NAME) :
	$(CC) $(FLAGS) $(MLX) $(SRC) -o $(NAME)
$(B_NAME) :
	$(CC) $(FLAGS) $(MLX) $(B_SRCS) -o $(B_NAME)
all : $(NAME)
bonus : $(B_NAME)
clean :
	rm -f $(NAME)
	rm -f $(B_NAME)
fclean : clean
	rm -f $(NAME)
	rm -f $(B_NAME)
re : clean fclean all

.PHONY : all clean fclean re