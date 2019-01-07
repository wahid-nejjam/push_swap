# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 11:31:30 by conoel            #+#    #+#              #
#    Updated: 2019/01/07 16:42:34 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ./includes/ft_printf.h

SRC_NAME = \

SRC = $(addprefix ./srcs/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix ./obj/, $(OBJ_NAME))

.PHONY: clean fclean all re heil

all: obj $(NAME)

obj:
		@mkdir -p obj

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "Created Lib file ($(NAME)) !"

./obj/%.o: ./srcs/%.c
		@gcc -Ofast -Wextra -Werror -Wall -c $< -o $@ -I$(HEADER)
		#@gcc -c $< -o $@ -I$(HEADER)

clean:
		@rm -rf ./obj/*.o
		@echo "Removed all .o files"

fclean: clean
		@rm -rf $(NAME)
		@echo "Removed $(NAME) file"

re: fclean all

#heil: all
#/		@gcc main.c $(NAME) -I$(HEADER)
#		@echo "\n#>======= -- =======<#\n#       ~ ~~ ~       #\n#\033[31m\033[1m Heil Anne Franck ! \033[00m#\n#       ~ ~~ ~       #\n#>======= -- =======<#"
