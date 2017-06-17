#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:47:20 by abrichar          #+#    #+#              #
#    Updated: 2017/06/17 16:13:19 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FDFFLAGS = -lmlx -framework OpenGL -framework AppKit
CPPFLAGS = -Iincludes/

SRC_NAME = main.c parsing.c
SRC_PATH = src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft/libft.a


all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB) $(FDFFLAGS) $(CPPFLAGS)

clean:

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC_NAME)
