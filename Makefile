# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/02/12 05:48:04 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
#
#	VARIABLES
#
#

NAME = push_swap
FILE_NAME = quick_sort
NAME2 = checker

HEADER = include/push_swap.h

SRC_NAME = ft_free.c load_a.c new.c push.c rotate.c swap.c utils.c exec_ft.c\
print_stack_functions.c print_stack_functions2.c print_stack.c utils_quick.c\
ft_atoi_error.c small_sort.c medium_sort.c
SRCDIR = ./src/
SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJDIR = ./obj/
OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}

NAME2_OBJ = ${addprefix $(OBJDIR), $(NAME2).o}
NAME_OBJ = ${addprefix $(OBJDIR), $(FILE_NAME).o}

SRC_NOFLAG = ${addprefix ${addprefix $(SRC_DIR), $(SRC_NAME)}, noflag} 
OBJ_NOFLAG = $(SRCC_NOFLAG:.c=.o)

FT_PRINTF_NAME = ft_printf.a
FT_PRINTF_DIR = ./printf/
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_NAME))

LIBFT_NAME = libft.a
LIBFT_DIR = ./libft/
LIBFT = ${addprefix $(LIBFT_DIR), $(LIBFT_NAME)}

FLAGS = -Wall -Werror -Wextra -O3

#
#
#	RULES
#
#

.PHONY: all clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJ_NOFlAG) $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJ) $(NAME_OBJ)
	@clang $(FLAGS) $(OBJ) ./obj/$(FILE_NAME).o $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n      \033[34m\033[1m$(NAME) binary created successfully !\033[0m\n    \-------========= ~~ * ~~ =========-------/\n"

$(NAME2): $(LIBFT) $(FT_PRINTF) $(OBJDIR) $(OBJ) $(NAME2_OBJ)
	@clang $(FLAGS) $(OBJ) ./obj/$(NAME2).o $(LIBFT) $(FT_PRINTF) -o $(NAME2)
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
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(LIBFT)]";
	@make fclean -C printf
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(FT_PRINTF)]";
	@rm -rf $(OBJDIR) $(NAME) $(NAME2)
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(NAME)]";