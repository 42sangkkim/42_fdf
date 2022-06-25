NAME:=mlx_test

CC:=cc
CFLAGS:=

MLX_DIR:=minilibx_macos
MLX_NAME:=mlx
MLX_FLAGS:=-L$(MLX_DIR) -l$(MLX_NAME) -framework OpenGL -framework AppKit

INC_DIR:=incs
INCS:=fdf.h

SRC_DIR:=srcs
SRCS:=fdf.c init_fdf.c init_mlx.c update_fdf.c draw_fdf.c

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX_FLAGS)
