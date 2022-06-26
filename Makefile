NAME:=fdf

CC:=cc
CFLAGS:=#-Wall -Wextra -Werror

MLX_DIR:=minilibx_macos
MLX_NAME:=mlx
MLX_FLAGS:= -framework OpenGL -framework AppKit

LIBFT_DIR:=libft
LIBFT_NAME:=ft

INC_DIR:=incs
INCS:=fdf.h

SRC_DIR:=srcs
SRCS:=srcs/main.c srcs/init.c srcs/util1.c

$(NAME) : $(SRCS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ \
		-I $(MLX_DIR)/mlx.h -L$(MLX_DIR) -l$(MLX_NAME) $(MLX_FLAGS)\
		-I libft/libft.h -L$(LIBFT_DIR) -l$(LIBFT_NAME)
