# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/04/12 17:50:15 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#
#	VARIABLES
#
#

NAME = push_swap
NAME2 = checker

SRC_NAME = 	load_a.c new.c utils_quick.c ft_atoi_error.c exec_ft.c utils.c\
			push.c rotate.c swap.c\
			print_stack.c print_stack_functions.c print_stack_functions2.c\
			small_sort.c medium_sort.c long_sort.c very_long_sort.c
SRC_DIR = ./src/
SRC = ${addprefix $(SRC_DIR), $(SRC_NAME)}

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR = ./obj/
OBJ = ${addprefix $(OBJ_DIR), $(OBJ_NAME)}

NAME2_OBJ = ${addprefix $(OBJ_DIR), $(NAME2).o}
NAME_OBJ = ${addprefix $(OBJ_DIR), $(NAME).o}

HEADER_NAME = push_swap.h
HEADER_DIR = ./include/
HEADER = ${addprefix $(HEADER_DIR), $(HEADER_NAME)}

LIB_NAME = haflib.a
LIB_DIR = ./haflib/
LIB = ${addprefix $(LIB_DIR), $(LIB_NAME)}

FLAGS = -Wall -Werror -Wextra -Ofast

#
#
#	RULES
#
#

.PHONY: all clean fclean re

all: $(LIB) $(OBJ_DIR) $(OBJ_NOFlAG) $(NAME) $(NAME2)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ) $(NAME_OBJ) $(HEADER)
	@clang $(FLAGS) $(OBJ) ./obj/$(NAME).o $(LIB) -o $(NAME)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n      \033[34m\033[1m$(NAME) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2): $(LIB) $(OBJ_DIR) $(OBJ) $(NAME2_OBJ) $(HEADER)
	@clang $(FLAGS) $(OBJ) ./obj/$(NAME2).o $(LIB) -o $(NAME2)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n       \033[33m\033[1m$(NAME2) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

################################################################
######                       LIBS                         ######
################################################################

$(LIB):
	@make -C $(LIB_DIR)

################################################################
######                    OBJECTS                         ######
################################################################

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
	@echo "\n>========= * \033[32m\033[1mCreating $(NAME) obj dir\033[0m * =========<\n";

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@clang $(FLAGS) -c $< -o $@ -I$(HEADER_DIR)
	@echo "\033[32m\033[1m\033[4mCompilating\033[0m\033[32m : $@\033[0m [$(NAME)]";

################################################################
######                      GENERAL                       ######
################################################################

re: fclean all

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)

fclean:
	@make fclean -C $(LIB_DIR)
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(LIB)]";
	@rm -rf $(OBJ_DIR) $(NAME) $(NAME2)
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(NAME)]";
