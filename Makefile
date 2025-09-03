# Executable Name
NAME = cub3d

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

# Headers
HEADERS = -Iincludes -Idependencies/libft/includes -Idependencies/mlx-linux

# Libraries
LIBS = -lXext -lX11 -lm

# Minilibx
MLX_PATH = dependencies/mlx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH = dependencies/libft
LIBFT = $(LIBFT_PATH)/libft.a

# Source and Object files
SRC_PATH = src/
# Use a more CLion-friendly approach to find sources
SRC = $(shell find $(SRC_PATH) -name "*.c")

OBJ_PATH = obj/
OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

# Build the executables
all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(MLX):
	@make -sC $(MLX_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(LIBS)

clean:
	rm -rf $(OBJ_PATH)
	@make -sC $(MLX_PATH) clean
	@make -sC $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@make -sC $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re