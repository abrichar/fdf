#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:47:20 by abrichar          #+#    #+#              #
#    Updated: 2017/07/04 14:46:56 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FDFFLAGS = -lmlx -framework OpenGL -framework AppKit
CPPFLAGS = -Iincludes/ -I /usr/local/include
CFLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c parsing.c
SRC_PATH = src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft/libft.a
MinilibX = MinilibX/libmlx.a


all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(SRC) $(LIB) $(MinilibX) $(CPPFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC_NAME)
