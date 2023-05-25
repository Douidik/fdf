NAME = fdf

LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
MLX_DIR = ./minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
MLX = $(MLX_DIR)/libmlx.a

FILES_C = \
camera.c \
camera_nav.c \
nav.c \
fdf.c \
fdf_hook.c \
main.c \
map.c \
window.c \
math/cohen_sutherland.c \
math/lerp.c \
math/intersect.c \
math/mat.c \
math/mat_mul.c \
math/mat_rotate.c \
math/mat_projection.c \
math/mat_transform.c \
parse/parser.c \
parse/scan.c \
util/cmp.c \
util/mem.c \
util/read_fd.c \
render/draw_map.c \
render/draw_nav.c \
render/draw_pixel.c \
render/draw_segment.c \
render/map_shader.c \
render/renderer.c \

SRC_DIR = ./src
BIN_DIR = ./bin

CC = cc
SRC = $(addprefix $(SRC_DIR)/,$(FILES_C))
OBJ = $(addprefix $(BIN_DIR)/,$(FILES_C:.c=.o))
INC = -I $(SRC_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(MLX_DIR)

# CFLAGS = -g -Wall -Wextra -Werror -lXext -lX11 -lm -lz
CFLAGS = -g -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(MLX) $(BIN_DIR) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) $(LIBFT) $(FT_PRINTF) $(MLX)

$(LIBFT):
	make -C $(LIBFT_DIR) bonus

$(FT_PRINTF):
	make -C $(FT_PRINTF_DIR) bonus

$(MLX):
	make -C $(MLX_DIR)

$(BIN_DIR):
	mkdir -p $(dir $(OBJ))

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FT_PRINTF_DIR) clean
	rm -rf $(BIN_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FT_PRINTF_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY = all clean fclean re
