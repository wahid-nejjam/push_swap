/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:59:12 by conoel            #+#    #+#             */
/*   Updated: 2019/02/04 14:29:29 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			print_sb(t_elem *b)
{
	if (b->next->root)
		printf("[\033[36m%d\033[0m]  |\033[32m<-\\\033[0m\n", b->nb);
	else if (b->next->next->root)
		printf("[\033[36m%d\033[0m]  |\033[32m--/\033[0m\n", b->nb);
	else
		printf("[\033[36m%d\033[0m]  |  \033[32m|\033[0m\n", b->nb);
}

static int		get_print_height(t_elem *a, t_elem *b)
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

static void		print_b(t_elem *b, char *ft)
{
	if (b->root)
		printf("     |\n");
	else
	{
		if (ft_strcmp(ft, "rb") == 0)
			print_rb(b);
		else if (ft_strcmp(ft, "rrb") == 0)
			print_rrb(b);
		else if (ft_strcmp(ft, "sb") == 0)
			print_sb(b);
		else
			printf("[\033[36m%d\033[0m]  |\n", b->nb);
	}
}

static void		print_a(int col, t_elem *a, t_elem *mark, char *ft)
{
	if (a->root)
	{
		print_char_str(' ', (col / 2) - 10);
		printf("|          ");
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
			printf(a != mark ? "   |  [\033[31m%d\033[0m]\033[32m---->\033[0m" :
"   |  [\033[34m%d\033[0m]\033[32m---->\033[0m", a->nb);
		else if (ft_strcmp(ft, "pb") == 0 && a->next->root)
			printf(a != mark ? "   |  [\033[31m%d\033[0m]\033[32m<----\033[0m" :
"   |  [\033[34m%d\033[0m]\033[32m<----\033[0m", a->nb);
		else
			printf(a != mark ? "   |  [\033[31m%d\033[0m]     " :
"   |  [\033[34m%d\033[0m]     ", a->nb);
	}
}

void			print_stack(t_elem *a, t_elem *b, char *ft, t_elem *mark)
{
	struct 			winsize	window;
	int				print_height;
	char			buffer[BUFF + 1];

	ioctl(0, TIOCGWINSZ, &window);
	ft_bzero(buffer, BUFF + 1);
	b = b->previous;
	a = a->previous;
	print_height = get_print_height(a, b);
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
	print_char_str(' ', (window.ws_col / 2) - 13);
	write(1, "    \\____/*~*\\____/\n", 19);
	print_char_str('\n', (window.ws_row - print_height) / 2);
	write(1, ft, 3);
}
