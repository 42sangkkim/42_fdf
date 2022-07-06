# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 00:12:03 by sangkkim          #+#    #+#              #
#    Updated: 2022/07/07 03:07:52 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME=fdf

MANDATORY_DIR=mandatory

BONUS_DIR=bonus

MLX_DIR=minilibx

FT_DIR=libft

ifdef TARGET_DIR
else
TARGET_DIR=$(MANDATORY_DIR)
endif

RM=rm
RMFLAGS=-f

$(NAME) : $(TARGET_DIR)/$(NAME)
	cp $^ ./

$(TARGET_DIR)/$(NAME) :
	@make -C $(MLX_DIR)
	@make -C $(FT_DIR)
	make -C $(TARGET_DIR)
	


.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	make -C $(MLX_DIR) clean
	make -C $(FT_DIR) clean
	make -C $(BONUS_DIR) clean
	make -C $(MANDATORY_DIR) clean

fclean : clean
	make -C $(FT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	@make TARGET_DIR:=$(BONUS_DIR) all
