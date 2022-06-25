NAME:=mlx_test

CC:=cc
CFLAGS:=

MLX_DIR:=minilibx_macos
MLX_NAME:=mlx
MLX_FLAGS:=-L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

SRCS:=main.c

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)
