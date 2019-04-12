/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_long_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:31:35 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:36:43 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		very_long_sort(t_elem *root_a, t_elem *root_b, int delay)
{
	while (root_a->next != root_a)
	{
		cut_a(root_a, root_b, get_pourcentage(root_a, 0.5), delay);
		if (heap_size(root_a) <= 15)
			solve_a(root_a, root_b, heap_size(root_a), delay);
	}
	while (root_b->next != root_b)
	{
		cut_b(root_a, root_b, get_pourcentage(root_b, 0.75), delay);
		if (heap_size(root_b) <= 15)
			solve_b(root_a, root_b, heap_size(root_b), delay);
	}
	while (root_a->next != root_a)
	{
		cut_a(root_a, root_b, get_pourcentage(root_a, 0.125), delay);
		if (heap_size(root_a) <= 15)
			solve_a(root_a, root_b, heap_size(root_a), delay);
	}
	solve_b(root_a, root_b, heap_size(root_b), delay);
}
