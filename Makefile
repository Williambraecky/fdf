# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 16:04:36 by wbraeckm          #+#    #+#              #
#    Updated: 2018/09/05 11:29:29 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -O3 -Wall -Wextra -Werror
INCLUDES = includes/
LIB_INCLUDES = libft/includes/
LIB_FOLDER = libft/
MLX_FOLDER = minilibx/
SRCSFOLDER = srcs
OBJFOLDER = obj
LIBFT = libft/libft.a
MLX = minilibx/libmlx.a
MLX_FLAGS = -framework OpenGL -framework AppKit

ITEMS = $(shell find srcs -type f | grep -E "\.c$$" | sed 's/srcs//g')
SRCS = $(addprefix $(SRCSFOLDER), $(ITEMS))
OBJ = $(addprefix $(OBJFOLDER), $(ITEMS:.c=.o))
SRCSUBS = $(shell find ./srcs -type d)
OBJSUBS = $(SRCSUBS:./srcs%=./obj%)

ccred = "\033[0;91m"
ccgreen = "\033[0;92m"
ccmagenta = "\033[0;96m"

all: $(LIBFT) $(MLX) $(NAME)

$(OBJFOLDER)/%.o:$(SRCSFOLDER)/%.c
	@printf $(ccgreen)
	$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIB_INCLUDES) -I $(MLX_FOLDER)

$(OBJSUBS):
	@mkdir $@

$(NAME): $(OBJSUBS) $(OBJ)
	@printf $(ccmagenta)
	gcc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
	@printf $(ccred)
	make clean -C $(LIB_FOLDER)
	make clean -C $(MLX_FOLDER)
	/bin/rm -rf obj/

fclean: clean
	make fclean -C $(LIB_FOLDER)
	rm -f $(MLX)
	/bin/rm -f $(NAME)

re: fclean all

norm:
	@norminette srcs/ includes/ $(LIB_FOLDER)srcs $(LIB_INCLUDES)

re-mlx:
	make re -C $(MLX_FOLDER)

re-lib:
	make re -C $(LIB_FOLDER)

$(MLX):
	make -C $(MLX_FOLDER)

$(LIBFT):
	make -C $(LIB_FOLDER)

.PHONY: norm clean fclean re
