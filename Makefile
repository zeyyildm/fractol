NAME = fractol

SRCS = main.c inits.c
OBJS = $(SRCS:.c=.o)

CC = cc
MLX_PATH = ./minilibx-linux
MLX = ./minilibx-linux/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = ./libft/libft.a


all: $(NAME) $(LIBFT) $(MLX)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./minilibx-linux

clean:
	$(RM) $(OBJS)
	@make clean -C ./libft
	@make clean -C $(MLX_PATH)

fclean: clean
	$(RM) $(NAME)
	@make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re