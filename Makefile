# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 16:04:36 by wbraeckm          #+#    #+#              #
#    Updated: 2018/08/24 14:06:01 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -O3 -Wall -Wextra -Werror
INCLUDES = includes/
LIB_INCLUDES = libft/includes/
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

all: $(NAME)

$(OBJFOLDER)/%.o:$(SRCSFOLDER)/%.c
	@printf $(ccgreen)
	$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIB_INCLUDES) -I $(MLX_FOLDER)

$(OBJSUBS):
	@mkdir $@

$(NAME): lib mlx $(OBJSUBS) $(OBJ)
	@printf $(ccmagenta)
	@make compile

compile:
	gcc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean:
	@printf $(ccred)
	/bin/rm -rf obj/

fclean: clean
	/bin/rm -f $(NAME)

re: re-lib re-mlx fclean all

norm:
	@norminette srcs/ includes/

re-mlx:
	@make re -C minilibx/

re-lib:
	@make re -C libft/

mlx:
	@make -C minilibx/

lib:
	@make -C libft/

.PHONY: norm clean fclean re lib mlx
