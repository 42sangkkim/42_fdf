# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 00:12:03 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/05 00:23:13 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

MANDATORY_DIR=mandatory

BONUS_DIR=bonus

MLX_DIR=minilibx

LIBFT_DIR=libft

ifdef TARGET_DIR
else
TARGET_DIR=$(MANDATORY_DIR)
endif

RM=rm
RMFLAGS=-f

$(NAME) : $(SRCS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	make -C $(TARGET_DIR)
	cp $(TARGET_DIR)/$(NAME) ./

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(MANDATORY_DIR) clean
	make -C $(MANDATORY_DIR) clean

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	@make TARGET_DIR:=$(BONUS_DIR) all
