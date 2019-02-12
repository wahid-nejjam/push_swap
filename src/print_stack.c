/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:59:12 by conoel            #+#    #+#             */
/*   Updated: 2019/02/12 00:08:20 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		print_b(t_elem *b, char *ft)
{
	if (b->root)
		ft_printf("     |\n");
	else
	{
		if (ft_strcmp(ft, "rb") == 0)
			print_rb(b);
		else if (ft_strcmp(ft, "rrb") == 0)
			print_rrb(b);
		else if (ft_strcmp(ft, "sb") == 0)
			print_sb(b);
		else
			ft_printf("[\033[36m%d\033[0m]  |\n", b->nb);
	}
}

static void		print_a(int col, t_elem *a, t_elem *mark, char *ft)
{
	if (a->root)
	{
		print_char_str(' ', (col / 2) - 10);
		ft_printf("|          ");
	}
	else
	{
		print_char_str(' ', (col / 2) - 13);
		if (ft_strcmp(ft, "ra") == 0)
			print_ra(a, mark);
		else if (ft_strcmp(ft, "rra") == 0)
			print_rra(a, mark);
		else if (ft_strcmp(ft, "sa") == 0)
			print_sa(a, mark);
		else if (ft_strcmp(ft, "pa") == 0 && a->next->root)
			ft_printf(a != mark ?
	"   |  [\033[31m%d\033[0m]\033[32m---->\033[0m" :
	"   |  [\033[34m%d\033[0m]\033[32m---->\033[0m", a->nb);
		else if (ft_strcmp(ft, "pb") == 0 && a->next->root)
			ft_printf(a != mark ?
	"   |  [\033[31m%d\033[0m]\033[32m<----\033[0m" :
	"   |  [\033[34m%d\033[0m]\033[32m<----\033[0m", a->nb);
	}
}

static void		print_footer(struct winsize window, int print_height)
{
	print_char_str(' ', (window.ws_col / 2) - 13);
	write(1, "    \\____/*~*\\____/\n", 19);
	print_char_str('\n', (window.ws_row - print_height) / 2);
}

void			print_stack(t_elem *a, t_elem *b, char *ft, t_elem *mark)
{
	struct winsize	window;
	int				print_height;

	ioctl(0, TIOCGWINSZ, &window);
	b = b->previous;
	a = a->previous;
	print_height = get_print_height(a, b);
	if (window.ws_row <= heap_size(a) + 2)
	{
		write(2, "Way too big !\n", 13);
		return ;
	}
	print_char_str('\n', (window.ws_row - print_height) / 2);
	print_char_str(' ', (window.ws_col / 2) - 13);
	write(1, "     /{Push_swap}\\ \n", 20);
	print_char_str(' ', (window.ws_col / 2) - 13);
	write(1, "    /  A  \\./  B  \\\n", 20);
	while (!a->root || !b->root)
	{
		print_a(window.ws_col, a, mark, ft);
		print_b(b, ft);
		a = (a->root ? a : a->previous);
		b = (b->root ? b : b->previous);
	}
	print_footer(window, print_height);
}
