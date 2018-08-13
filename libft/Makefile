# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbraeckm <wbraeckm@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 08:11:26 by wbraeckm          #+#    #+#              #
#    Updated: 2018/07/24 22:10:04 by wbraeckm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -O3 -Wall -Wextra -Werror
INCLUDES = includes/
SRCSFOLDER = srcs
OBJFOLDER = obj

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
	$(CC) $(FLAGS) -o $@ -c $< -I $(INCLUDES)

$(OBJSUBS):
	@mkdir $@

$(NAME): $(OBJSUBS) $(OBJ)
	@printf $(ccmagenta)
	@make compile

compile:
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@printf $(ccred)
	/bin/rm -rf obj/

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norm:
	@norminette srcs/ includes/

.PHONY: norm clean fclean re
