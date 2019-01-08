# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 12:48:47 by conoel            #+#    #+#              #
#    Updated: 2019/01/08 19:31:36 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = include/push_swap.h

SRC_NAME = ft_atoi.c ft_bzero.c ft_strcmp.c print_stack.c new.c load_a.c\
push.c swap.c rotate.c checker.c 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = ${addprefix ./src/, $(SRC_NAME)}

OBJ = ${addprefix ./obj/, $(OBJ_NAME)}


.PHONY: all checker clean fclean re

all: obj checker

obj:
	@mkdir -p obj
	@echo "\n\033[35m\033[1m======= * Creating obj dir * =======\033[0m\n"

./obj/%.o: ./src/%.c
	@clang -Ofast -Wextra -Werror -Wall -c $< -o $@
	@echo "\033[35mCompilating : $@\033[0m";

checker: $(OBJ)
	@clang $(OBJ) -o checker
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[34m\033[1mChecker binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f checker
	@rm -Rf ./obj
	@echo "\033[36m               ~ --- ~\n*< Everything have been removed. >*\n               ~ --- ~"

re: fclean all
