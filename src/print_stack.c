/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:59:12 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 13:11:07 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		print_stack(t_elem *last)
{
	t_elem	*mem;

	mem = last->next;
	write(1, "Liste_a\n", 9);
	while (mem != last)
	{
		printf("|%d|\n", last->nb);
		last = last->previous;
	}
	printf("|%d|\n", last->nb);
	write(1, "\n", 1);
}