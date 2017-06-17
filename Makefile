#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:47:20 by abrichar          #+#    #+#              #
#    Updated: 2017/06/17 15:34:01 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FDF_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_NAME = main.c
SRC_PATH = src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft/libft.a


all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB) $(FDF_FLAGS)

clean:

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC_NAME)
