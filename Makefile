# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/02/01 19:46:04 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

HEADER = include/push_swap.h

SRC_NAME = ft_free.c load_a.c new.c print_stack.c push.c rotate.c swap.c utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJDIR = ./obj/

SRCDIR = ./src/

SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}

NAME_OBJ = ${addprefix $(OBJDIR), $(NAME).o}

NAME2_OBJ = ${addprefix $(OBJDIR), $(NAME2).o}

LIBFT_NAME = libft.a

LIBFT_DIR = ./libft/

LIBFT = ${addprefix $(LIBFT_DIR), $(LIBFT_NAME)}

.PHONY: all clean fclean re

all: $(LIBFT) $(OBJDIR) $(OBJ) $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(OBJDIR) $(OBJ) $(NAME_OBJ)
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME).o -o $(NAME) libft/libft.a
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n       \033[34m\033[1m$(NAME) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2): $(LIBFT) $(OBJDIR) $(OBJ) $(NAME2_OBJ)
	@clang -Werror -Wextra -Wall $(OBJ) ./obj/$(NAME2).o -o $(NAME2) libft/libft.a
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n       \033[33m\033[1m$(NAME2) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

$(LIBFT):
	@make -C libft

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "\n>========= * \033[32m\033[1mCreating $(NAME) obj dir\033[0m * =========<\n";

$(OBJDIR)%.o: $(SRCDIR)%.c
	@clang -Wall -Werror -Wextra -c $< -o $@ 
	@echo "\033[32m\033[1m\033[4mCompilating\033[0m\033[32m : $@\033[0m [$(NAME)]";

re: fclean all

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft

fclean:
	@make fclean -C libft
	@rm -rf $(OBJDIR) $(NAME) $(NAME2)
	@echo "               ~ --- ~\n*< \033[36mEverything has been removed.\033[0m >*\n               ~ --- ~"
