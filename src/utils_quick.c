/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:30:29 by conoel            #+#    #+#             */
/*   Updated: 2019/02/12 05:28:49 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*get_at_index(t_elem *root, int index)
{
	t_elem *tmp;

	tmp = root->next;
	while (index-- && root != root->next && !tmp->next->root)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

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

int		not_sort(t_elem *root)
{
	int		ret;
	t_elem	*tmp;

	ret = 0;
	tmp = root->next;
	while (!issort(tmp) && tmp->next != root)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}

void	cut_a(t_elem *root_a, t_elem *root_b, int mid_value, int delay)
{
	while (ft_get_max(root_a)->nb >= mid_value && root_a->next != root_a)
	{
		if (root_a->previous->nb >= mid_value)
			exec_ft("pa", root_a, root_b, delay);
		else
			exec_ft("ra", root_a, root_b, delay);
	}
}

void	cut_b(t_elem *root_a, t_elem *root_b, int mid_value, int delay)
{
	while (ft_get_min(root_b)->nb <= mid_value && root_b->next != root_b)
	{
		if (root_b->previous->nb <= mid_value)
			exec_ft("pb", root_a, root_b, delay);
		else
			exec_ft("rb", root_a, root_b, delay);
	}
}
