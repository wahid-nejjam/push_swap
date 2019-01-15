# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/01/15 13:28:50 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap_selection

NAME2 = checker

HEADER = include/push_swap.c

SRC_NAME = ft_atoi.c ft_bzero.c ft_free.c ft_memcmp.c ft_strcmp.c ft_strsplit.c\
load_a.c new.c print_stack.c push.c rotate.c swap.c utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJDIR = ./obj/

SRCDIR = ./src/

SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}


all: $(NAME) $(NAME2)

$(NAME): obj $(OBJ) ./obj/$(NAME).o
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME).o -o $(NAME)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[34m\033[1m$(NAME) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2): obj $(OBJ) ./obj/$(NAME2).o
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME2).o -o $(NAME2)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[33m\033[1m$(NAME2) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

obj:
	@mkdir -p $(OBJDIR)
	@echo "\n>========= * \033[35m\033[1mCreating obj dir\033[0m * =========<\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@clang -Wall -Werror -Wextra -c $< -o $@ 
	@echo "\033[35mCompilating : $@\033[0m";

re: fclean all

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME) $(NAME)_visual
	@echo "               ~ --- ~\n*< \033[36mEverything has been removed.\033[0m >*\n               ~ --- ~"
