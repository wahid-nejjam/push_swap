# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 12:48:47 by conoel            #+#    #+#              #
#    Updated: 2019/01/09 21:15:43 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER = include/push_swap.h

SRC_NAME = ft_atoi.c ft_bzero.c ft_strcmp.c print_stack.c new.c load_a.c\
push.c swap.c rotate.c ft_free.c ft_strsplit.c ft_memcmp.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = ${addprefix ./src/, $(SRC_NAME)}

OBJ = ${addprefix ./obj/, $(OBJ_NAME)}

.PHONY: all checker push_swap clean fclean re bonobo

all: checker pushswap

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f checker push_swap
	@rm -Rf ./obj
	@echo "               ~ --- ~\n*< \033[36mEverything have been removed.\033[0m >*\n               ~ --- ~"

re: fclean all

obj:
	@mkdir -p obj
	@echo "\n>========= * \033[35m\033[1mCreating obj dir\033[0m * =========<\n"

./obj/%.o: ./src/%.c
	@clang -Ofast -Wextra -Werror -Wall -c $< -o $@
	@echo "\033[35mCompilating : $@\033[0m";

checker: obj $(OBJ)
	@clang -Ofast -Wextra -Werror -Wall -c src/checker.c -o obj/checker.o
	@clang $(OBJ) obj/checker.o -o checker
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[34m\033[1mChecker binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

pushswap: obj $(OBJ)
	@clang -Ofast -Wextra -Werror -Wall -c src/push_swap_selection.c -o obj/push_swap_selection.o
	@clang $(OBJ) obj/push_swap_selection.o -o push_swap
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[33m\033[1mPushSwap binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

#  |=======================================|
#  |========= RANDOM SORT (BONUS) =========|
#  |=======================================|

bonobo: pushswap_r

pushswap_r: obj $(OBJ)
	@clang -Ofast -Wextra -Werror -Wall -c src/push_swap_random.c -o obj/push_swap_random.o
	@clang $(OBJ) obj/push_swap_random.o -o push_swap
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[33m\033[1mPushSwap binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

#  |=======================================|
#  |========= VISUAL MODE (BONUS) =========|
#  |=======================================|

v: checker_v pushswap_v

checker_v: obj $(OBJ)
	@clang -Ofast -Wextra -Werror -Wall -c src/checker_v.c -o obj/checker_v.o
	@clang $(OBJ) obj/checker_v.o -o checker_v
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[34m\033[1mChecker binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"
	@echo "                /---~---~*~---~---\ \n          --*  { \033[31m Visual mode : ON\033[0m }  *--\n                \---~---~*~---~---/\n"

pushswap_v: obj $(OBJ)
	@clang -Ofast -Wextra -Werror -Wall -c src/push_swap_v.c -o obj/push_swap_v.o
	@clang $(OBJ) obj/push_swap_v.o -o push_swap_v
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[33m\033[1mPushSwap binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"
	@echo "                /---~---~*~---~---\ \n          --*  { \033[31m Visual mode : ON\033[0m }  *--\n                \---~---~*~---~---/\n"