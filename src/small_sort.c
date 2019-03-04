/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:15:18 by conoel            #+#    #+#             */
/*   Updated: 2019/03/04 14:17:19 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	small_sort(t_elem *root_a, t_elem *root_b, int delay)
{
	t_elem	*top;

	while (!issort(root_a))
	{
		top = root_a->previous;
		if (top->nb > top->previous->nb)
		{
			exec_ft("sa", root_a, root_b, delay);
		}
		else
		{
			exec_ft("rra", root_a, root_b, delay);
		}
	}
}
