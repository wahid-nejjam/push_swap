/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:32:28 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:36:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		long_sort(t_elem *root_a, t_elem *root_b, int delay)
{
	float a;

	a = 0.28;
	while (root_a->next != root_a && !issort(root_a))
	{
		cut_a(root_a, root_b, get_pourcentage(root_a, a), delay);
		if (heap_size(root_a) <= 13)
			solve_a(root_a, root_b, heap_size(root_a), delay);
	}
	solve_b(root_a, root_b, heap_size(root_b), delay);
}
