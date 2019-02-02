/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:59:12 by conoel            #+#    #+#             */
/*   Updated: 2019/02/02 03:11:06 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_print_height(t_elem *a, t_elem *b)
{
	int		ret;

	ret = 2;
	while (!a->root || !b->root)
	{
		a = (a->root ? a : a->previous);
		b = (b->root ? b : b->previous);
		ret++;
	}
	return (ret);
}

void		print_stack(t_elem *a, t_elem *b, char *ft, t_elem *mark)
{
	struct winsize	window;
	int				print_height;
	
	ioctl(0, TIOCGWINSZ, &window);
	b = b->previous;
	a = a->previous;
	print_height = get_print_height(a, b);
	print_char_str('\n', (window.ws_row - print_height) / 2);
	if (ft_strcmp(ft, "pa") == 0)
	{
		print_char_str(' ', (window.ws_col / 2) - 9);
		write(1, "\033[32m------------->\033[0m\n\n", 24);
	}
	if (ft_strcmp(ft, "pb") == 0)
	{
		print_char_str(' ', (window.ws_col / 2) - 9);
		write(1, "\033[33m<-------------\033[0m\n\n", 24);
	}
	print_char_str(' ', (window.ws_col / 2) - 13);
	if (ft_strcmp(ft, "ra") == 0)
		write(1, "\033[35m^\033[0m    /{Push_swap}\\\n", 28);
	else
		write(1, "     /{Push_swap}\\ \n", 20);
	print_char_str(' ', (window.ws_col / 2) - 13);
	if (ft_strcmp(ft, "ra") == 0)
		write(1, "\033[35m|\033[0m   /  A  \\./  B  \\\n", 29);
	else
		write(1, "    /  A  \\./  B  \\\n", 20);
	while (!a->root || !b->root)
	{
		print_char_str(' ', (window.ws_col / 2) - 13);
		if (ft_strcmp(ft, "ra") == 0 || ft_strcmp(ft, "rra") == 0)
		{
			if (a == mark)
				printf(a->root ? "\033[35m|\033[0m  |         " : "\033[35m|\033[0m  |  [\033[34m%d\033[0m]    ", a->nb);
			else
				printf(a->root ? "\033[35m|\033[0m  |         " : "\033[35m|\033[0m  |  [\033[31m%d\033[0m]    ", a->nb);
		}
		else
		{
			if (a == mark)
				printf(a->root ? "   |         " : "   |  [\033[34m%d\033[0m]    ", a->nb);
			else
				printf(a->root ? "   |         " : "   |  [\033[31m%d\033[0m]    ", a->nb);
		}
		a = (a->root ? a : a->previous);
		printf(b->root ? "      |\n" : " [\033[36m%d\033[0m]  |\n", b->nb);
		b = (b->root ? b : b->previous);
	}
	print_char_str(' ', (window.ws_col / 2) - 13);
	if (ft_strcmp(ft, "rra") == 0)
		write(1, "\033[35mV\033[0m   \\____/*~*\\____/\n", 28);
	else
		write(1, "    \\____/*~*\\____/\n", 19);
	print_char_str('\n', (window.ws_row - print_height) / 2);
}
