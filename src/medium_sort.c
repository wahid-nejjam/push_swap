/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:48:44 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:26:04 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_elem *root_a, t_elem *root_b, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_a)->next);
	while (issort(root_a) == 0)
	{
		tmp = ft_get_min(root_a);
		index = ft_get_index(tmp);
		if (index > size / 2)
		{
			while ((root_a)->previous != tmp)
			{
				exec_ft("rra", root_a, root_b, delay);
			}
		}
		else
			while ((root_a)->previous != tmp)
				exec_ft("ra", root_a, root_b, delay);
		exec_ft("pb", root_a, root_b, delay);
		size--;
	}
	while ((root_b)->next != root_b)
		exec_ft("pa", root_a, root_b, delay);
}
