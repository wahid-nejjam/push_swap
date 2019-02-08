# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/02/07 16:11:25 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

HEADER = ./includes/ft_printf.h

SRC_NAME = ft_printf.c get_args.c ft_size_flags.c additional_converters.c \
ft_ftoa.c ft_itoa_base_unsigned.c ft_itoa_base_signed.c ft_ptoa.c\
ft_bzero.c ft_strcmp.c ft_strlen.c ft_strcat2.c ft_memset.c ft_strdup.c ft_atoi.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJDIR = ./obj/

SRCDIR = ./src/

SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}

.PHONY: all obj re clean fclean

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@echo "\n>========= * \033[32m\033[1mCreating $(NAME) obj dir\033[0m * =========<\n";

$(OBJDIR)%.o: $(SRCDIR)%.c
	@clang -Ofast -Wall -Werror -Wextra -c $< -o $@ 
	@echo "\033[32m\033[1m\033[4mCompilating\033[0m\033[32m : $@\033[0m [$(NAME)]";

re: fclean all

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
