# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 20:07:42 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/04 21:04:21 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

SRCS := main.c init_file.c init_fdf.c hooks.c transform.c draw_fdf.c \
		get_next_line.c utils1.c utils2.c

CC := cc
CCFLAGS :=# -Wall -Wextra -Werror

RM := rm
RMFLAGS := -f

LIBFT_DIR := ../libft
LIBFT := ft

MLX_DIR := ../minilibx
MLX := mlx

$(NAME) : $(SRCS)
	$(CC) $(CCFLAGS) -o $@ $^ \
	-I $(LIBFT_DIR) -L $(LIBFT_DIR) -l $(LIBFT) \
	-I $(MLX_DIR) -L $(MLX_DIR) -l $(MLX) -framework OpenGL -framework AppKit

.PHONY : all clean fclean re

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(NAME)

fclean : clean

re : fclean all
