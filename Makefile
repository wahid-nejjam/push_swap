# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 12:48:47 by conoel            #+#    #+#              #
#    Updated: 2019/01/08 12:48:53 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = swap.c load_a.c checker.c ft_atoi.c ft_strcmp.c rotate.c
SRCD = src/
HDR = push_swap.h
HDRD = include/
OBJ = $(SRC:.c=.o)
SRCF = ${addprefix $(SRCD), $(SRC)}
HDRF = ${addprefix $(HDRD), $(HDR)}

all: checker clean

checker:
	@gcc -Wall -Werror -Wextra -c $(SRCF)
	@gcc $(OBJ) -o checker

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f checker

re: fclean all
