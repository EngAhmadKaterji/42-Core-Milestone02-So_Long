# Compiler
CC      = gcc
AR      = ar rcs
RM      = rm -f
MD      = mkdir -p
CP      = cp -f

# Directories
SRC_DIR = srcs/
OBJ_DIR = obj/
INC_DIR = includes/
LIBFT   = libft.a
MDT_DIR = mandatory/
LIBFT_DIR = libft/
LIBFT_AR = $(LIBFT_DIR)$(LIBFT)

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
ifeq ($(shell uname), Linux)
    INCLUDES = -I$(MDT_DIR)$(INC_DIR) -I$(MDT_DIR)mlx
    MLX_DIR = mlx
    MLX_LIB = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm
else
    INCLUDES = -I$(MDT_DIR)$(INC_DIR) -I$(MDT_DIR)mlx
    MLX_DIR = mlx
    MLX_LIB = $(MLX_DIR)/libmlx.dylib
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -framework OpenGL -framework AppKit
endif

# Executable name
NAME = so_long

# Source files
SL_SRCS = so_long.c key_hook.c ft_read_map.c ft_put_player.c \
          ft_move.c ft_map_printer.c ft_map_checker.c ft_free.c \
          ft_file_to_image.c ft_error_handle.c ft_checker_valid_path.c
	/mandatory/srcs/so_long.c
SRCS := $(addprefix $(MDT_DIR)$(SRC_DIR), $(SL_SRCS))
OBJS := $(addprefix $(MDT_DIR)$(OBJ_DIR), $(SL_SRCS:.c=.o))

all: $(NAME)

# Compile .c files to .o files
$(MDT_DIR)$(OBJ_DIR)%.o: $(MDT_DIR)$(SRC_DIR)%.c | $(MDT_DIR)$(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link object files into executable
$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_AR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS) $(LIBFT_AR)

$(LIBFT_AR):
	make -C $(LIBFT_DIR) all

$(MDT_DIR)$(OBJ_DIR):
	$(MD) $(MDT_DIR)$(OBJ_DIR)

$(MLX_LIB):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(NAME)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
