# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/02/08 14:49:22 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#
#	VARIABLES
#
#

NAME = push_swap
NAME2 = checker

HEADER = include/push_swap.h

SRC_NAME = ft_free.c load_a.c new.c push.c rotate.c swap.c utils.c exec_ft.c\
print_stack_functions.c print_stack_functions2.c print_stack.c utils_quick.c
SRCDIR = ./src/
SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJDIR = ./obj/
OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}

NAME2_OBJ = ${addprefix $(OBJDIR), $(NAME2).o}
NAME_OBJ = ${addprefix $(OBJDIR), $(NAME).o}

SRC_NOFLAG = ${addprefix ${addprefix $(SRC_DIR), $(SRC_NAME)}, noflag} 
OBJ_NOFLAG = $(SRCC_NOFLAG:.c=.o)

FT_PRINTF_NAME = ft_printf.a
FT_PRINTF_DIR = ./printf/
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_NAME))

LIBFT_NAME = libft.a
LIBFT_DIR = ./libft/
LIBFT = ${addprefix $(LIBFT_DIR), $(LIBFT_NAME)}

FLAGS = -Wall -Werror -Wextra -pedantic -O3

#
#
#	RULES
#
#

.PHONY: all clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJ_NOFlAG) $(NAME) $(NAME2)

$(OBJDIR)%noflag.o: $(SRCDIR)%.c
	@clang -c $< -o $@ 
	@echo "\033[32m\033[1m\033[4mCompilating\033[0m\033[32m : $@\033[0m [$(NAME)]";

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJ) $(NAME_OBJ)
	@clang $(FLAGS) $(OBJ) ./obj/$(NAME).o -o $(NAME) $(LIBFT) $(FT_PRINTF)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n      \033[34m\033[1m$(NAME) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2): $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJ) $(NAME2_OBJ)
	@clang $(FLAGS) $(OBJ) ./obj/$(NAME2).o -o $(NAME2) $(LIBFT) $(FT_PRINTF)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n       \033[33m\033[1m$(NAME2) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

################################################################
######                       LIBS                         ######
################################################################

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

################################################################
######                    OBJECTS                         ######
################################################################

$(OBJDIR):
	@mkdir $(OBJDIR)
	@echo "\n>========= * \033[32m\033[1mCreating $(NAME) obj dir\033[0m * =========<\n";

$(OBJDIR)%.o: $(SRCDIR)%.c
	@clang $(FLAGS) -c $< -o $@ 
	@echo "\033[32m\033[1m\033[4mCompilating\033[0m\033[32m : $@\033[0m [$(NAME)]";

################################################################
######                      GENERAL                       ######
################################################################

re: fclean all

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft
	@make clean -C printf

fclean:
	@make fclean -C libft
	@make fclean -C printf
	@rm -rf $(OBJDIR) $(NAME) $(NAME2)
	@echo "               ~ --- ~\n*< \033[36mEverything has been removed.\033[0m >*\n               ~ --- ~"

################################################################
######                    NO_FLAG                         ######
################################################################

noflag: $(LIBFT) $(OBJDIR) $(OBJ) $(NAME)_noflag $(NAME2)_noflag

$(NAME)_noflag: $(FT_LIBFT) $(PRINTF) $(OBJDIR) $(OBJ_NOFLAG) $(OBJDIR)$(NAME)noflag.o
	@clang $(OBJ) ./obj/$(NAME)noflag.o -o $(NAME) $(LIBFT) $(FT_PRINTF)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n      \033[34m\033[1m$(NAME) noflag binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2)_noflag: $(FT_LIBFT) $(PRINTF) $(OBJDIR) $(OBJ_NOFLAG) $(OBJDIR)$(NAME2)noflag.o
	@clang $(OBJ) ./obj/$(NAME2)noflag.o -o $(NAME2) $(LIBFT) $(FT_PRINTF)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n      \033[34m\033[1m$(NAME2) noflag binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"
