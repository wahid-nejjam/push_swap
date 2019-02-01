# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/02/01 05:48:57 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

HEADER = include/push_swap.c

SRC_NAME = ft_free.c load_a.c new.c print_stack.c push.c rotate.c swap.c utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJDIR = ./obj/

SRCDIR = ./src/

SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}


all: obj $(OBJ) ./obj/$(NAME).o ./obj/$(NAME2).o
	@make -C libft
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME).o -o $(NAME) libft/libft.a
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME2).o -o $(NAME2) libft/libft.a
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[34m\033[1m$(NAME) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[33m\033[1m$(NAME2) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME): obj $(OBJ) ./obj/$(NAME).o
	@make -C libft
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME).o -o $(NAME) libft/libft.a
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[34m\033[1m$(NAME) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2): obj $(OBJ) ./obj/$(NAME2).o
	@make -C libft
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME2).o -o $(NAME2) libft/libft.a
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
	@make clean -C libft

fclean:
	@make fclean -C libft
	@rm -rf $(OBJDIR) $(NAME) $(NAME)
	@echo "               ~ --- ~\n*< \033[36mEverything has been removed.\033[0m >*\n               ~ --- ~"
