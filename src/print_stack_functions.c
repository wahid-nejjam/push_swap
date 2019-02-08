/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:02:34 by conoel            #+#    #+#             */
/*   Updated: 2019/02/07 15:58:38 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_ra(t_elem *a, t_elem *mark)
{
	if (a->next->root)
		ft_printf(a != mark ? "\033[32m/->\033[0m|  [\033[31m%d\033[0m]     " :
	"\033[32m/->\033[0m|  [\033[34m%d\033[0m]     ", a->nb);
	else if (a->previous->root == 1)
		ft_printf(a != mark ? "\033[32m\\--\033[0m|  [\033[31m%d\033[0m]     " :
	"\033[32m\\--\033[0m|  [\033[34m%d\033[0m]     ", a->nb);
	else
		ft_printf(a != mark ? "\033[32m|\033[0m  |  [\033[31m%d\033[0m]     " :
	"\033[32m|\033[0m  |  [\033[34m%d\033[0m]     ", a->nb);
}

void	print_rra(t_elem *a, t_elem *mark)
{
	if (a->next->root)
		ft_printf(a != mark ? "\033[32m/--\033[0m|  [\033[31m%d\033[0m]     " :
	"\033[32m/--\033[0m|  [\033[34m%d\033[0m]     ", a->nb);
	else if (a->previous->root)
		ft_printf(a != mark ? "\033[32m\\->\033[0m|  [\033[31m%d\033[0m]     " :
	"\033[32m\\->\033[0m|  [\033[34m%d\033[0m]     ", a->nb);
	else
		ft_printf(a != mark ? "\033[32m|\033[0m  |  [\033[31m%d\033[0m]     " :
	"\033[32m|\033[0m  |  [\033[34m%d\033[0m]     ", a->nb);
}

void	print_sa(t_elem *a, t_elem *mark)
{
	if (a->next->root)
		ft_printf(a != mark ? "\033[32m/--\033[0m|  [\033[31m%d\033[0m]     " :
	"\033[32m/--\033[0m|  [\033[34m%d\033[0m]     ", a->nb);
	else if (a->next->next->root)
		ft_printf(a != mark ? "\033[32m\\->\033[0m|  [\033[31m%d\033[0m]     " :
	"\033[32m\\->\033[0m|  [\033[34m%d\033[0m]     ", a->nb);
	else
		ft_printf(a != mark ? "   |  [\033[31m%d\033[0m]     " :
	"   |  [\033[34m%d\033[0m]     ", a->nb);
}

void	print_rrb(t_elem *b)
{
	if (b->next->root)
		ft_printf("[\033[36m%d\033[0m]  |\033[32m--\\\033[0m\n", b->nb);
	else if (b->previous->root)
		ft_printf("[\033[36m%d\033[0m]  |\033[32m<-/\033[0m\n", b->nb);
	else
		ft_printf("[\033[36m%d\033[0m]  |  \033[32m|\033[0m\n", b->nb);
}

void	print_rb(t_elem *b)
{
	if (b->next->root)
		ft_printf("[\033[36m%d\033[0m]  |\033[32m<-\\\033[0m\n", b->nb);
	else if (b->previous->root)
		ft_printf("[\033[36m%d\033[0m]  |\033[32m--/\033[0m\n", b->nb);
	else
		ft_printf("[\033[36m%d\033[0m]  |  \033[32m|\033[0m\n", b->nb);
}
