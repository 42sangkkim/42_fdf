NAME:=fdf

CC:=cc
CFLAGS:=#-Wall -Wextra -Werror

RM:=rm
RMFLAGS:= -f

MLX_DIR:=minilibx_macos
MLX_NAME:=mlx
MLX_FLAGS:= -framework OpenGL -framework AppKit

LIBFT_DIR:=libft
LIBFT_NAME:=ft

INC_DIR:=incs

SRC_DIR:=srcs
SRCS:=srcs/main.c srcs/init.c srcs/init_fdf.c srcs/update.c srcs/update_fdf.c srcs/draw_guide.c srcs/draw_fdf.c\
	  srcs/util1.c srcs/util2.c

$(NAME) : $(SRCS)
	make -C $(MLX_DIR)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $@ $^ \
		-I $(INC_DIR)\
		-I $(MLX_DIR) -L$(MLX_DIR) -l$(MLX_NAME) $(MLX_FLAGS)\
		-I $(LIBFT_DIR) -L$(LIBFT_DIR) -l$(LIBFT_NAME)

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
