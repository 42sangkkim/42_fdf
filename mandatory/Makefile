# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:07:42 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/05 00:08:26 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRCS := srcs/main.c srcs/init_file.c srcs/init_fdf.c srcs/hooks.c srcs/transform.c srcs/draw_fdf.c \
		srcs/get_next_line.c srcs/utils1.c srcs/utils2.c

INC_DIR := incs

CC := cc
CFLAGS :=# -Wall -Wextra -Werror

RM := rm
RMFLAGS := -f

LIBFT_DIR := ../libft
LIBFT := ft

MLX_DIR := ../minilibx
MLX := mlx

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) \
	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -l $(LIBFT) \
	-I $(MLX_DIR) -L $(MLX_DIR) -l $(MLX) -framework OpenGL -framework AppKit

.PHONY : all clean fclean re

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(NAME)

fclean : clean

re : fclean all
