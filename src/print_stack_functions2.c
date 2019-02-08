/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_functions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 01:49:48 by conoel            #+#    #+#             */
/*   Updated: 2019/02/07 15:58:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_sb(t_elem *b)
{
	if (b->next->root)
		ft_printf("[\033[36m%d\033[0m]  |\033[32m<-\\\033[0m\n", b->nb);
	else if (b->next->next->root)
		ft_printf("[\033[36m%d\033[0m]  |\033[32m--/\033[0m\n", b->nb);
	else
		ft_printf("[\033[36m%d\033[0m]  |  \033[32m|\033[0m\n", b->nb);
}

int		get_print_height(t_elem *a, t_elem *b)
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
