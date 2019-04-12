/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:30:29 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:36:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pourcentage(t_elem *root, float pourcent)
{
	int		median;
	int		min;
	int		max;

	min = ft_get_min(root)->nb;
	max = ft_get_max(root)->nb;
	median = ((max - min) * pourcent) + min;
	return (median);
}

void	cut_a(t_elem *root_a, t_elem *root_b, int mid_value, int delay)
{
	while (ft_get_min(root_a)->nb <= mid_value && root_a->next != root_a)
	{
		if (root_a->previous->nb <= mid_value)
			exec_ft("pb", root_a, root_b, delay);
		else
			exec_ft("ra", root_a, root_b, delay);
	}
}

void	cut_b(t_elem *root_a, t_elem *root_b, int mid_value, int delay)
{
	while (ft_get_max(root_b)->nb >= mid_value && root_b->next != root_b)
	{
		if (root_b->previous->nb >= mid_value)
			exec_ft("pa", root_a, root_b, delay);
		else
			exec_ft("rb", root_a, root_b, delay);
	}
}

void	solve_a(t_elem *root_a, t_elem *root_b, int max, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_a)->next);
	while (root_a->next != root_a && max--)
	{
		tmp = ft_get_min(root_a);
		index = ft_get_index(tmp);
		if (index > size / 2)
			while ((root_a)->previous != tmp)
				exec_ft("rra", root_a, root_b, delay);
		else
			while ((root_a)->previous != tmp)
				exec_ft("ra", root_a, root_b, delay);
		exec_ft("pb", root_a, root_b, delay);
		size--;
	}
}

void	solve_b(t_elem *root_a, t_elem *root_b, int max, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_b)->next);
	while (root_b->next != root_b && max--)
	{
		tmp = ft_get_max(root_b);
		index = ft_get_index(tmp);
		if (index > size / 2)
			while ((root_b)->previous != tmp)
				exec_ft("rrb", root_a, root_b, delay);
		else
			while ((root_b)->previous != tmp)
				exec_ft("rb", root_a, root_b, delay);
		exec_ft("pa", root_a, root_b, delay);
		size--;
	}
}
