#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:47:20 by abrichar          #+#    #+#              #
#    Updated: 2017/08/06 17:08:32 by abrichar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
UNAME := $(shell uname)

FRAMEWORK = -framework OpenGl -framework Appkit
CPPFLAGS = -Iincludes/ -I /usr/local/include
CFLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c parsing.c draw.c \
	draw_oct1.c draw_oct2.c draw_straight.c
SRC_PATH = src
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = libft/libft.a
MLX_Sierra = mlx_source/Sierra/libmlx.a
MLX_EL = mlx_source/other/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft; $(MAKE) -f Makefile
	@cd mlx_source; $(MAKE) -f Makefile
	ifeq ($(UNAME), Sierra)
	 	gcc -o $(NAME) $(SRC) $(LIB) $(MLX_Sierra) $(CPPFLAGS) $(FRAMEWORK)
	else
	 	gcc -o $(NAME) $(SRC) $(LIB) $(MLX_EL) $(CPPFLAGS) $(FRAMEWORK)
	endif

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@cd mlx_source; $(MAKE) -f Makefile clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(MLX)
	/bin/rm -f $(LIB)

re: fclean all

norme:
	norminette $(SRC_NAME)
