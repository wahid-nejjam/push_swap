# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 12:48:47 by conoel            #+#    #+#              #
#    Updated: 2019/01/08 16:54:02 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = include/push_swap.h

SRC_NAME = ft_atoi.c ft_bzero.c ft_strcmp.c print_stack.c\
push.c swap.c load_a.c rotate.c checker.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = ${addprefix ./src/, $(SRC_NAME)}

OBJ = ${addprefix ./obj/, $(OBJ_NAME)}


.PHONY: all checker clean fclean re

all: obj checker

obj:
	@mkdir -p obj
	@echo "\nCreating obj dir\n"

./obj/%.o: ./src/%.c
	@clang -Ofast -Wextra -Werror -Wall -c $< -o $@

checker: $(OBJ)
	@clang $(OBJ) -o checker
	@echo "    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[34m\033[1mChecker binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/"

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f checker
	@rm -Rf ./obj
	@echo "\nEverything have been removed.\n"

re: fclean all
