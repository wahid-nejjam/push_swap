/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:43:24 by conoel            #+#    #+#             */
/*   Updated: 2019/01/15 12:25:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		issort(t_elem *root_a)
{
	t_elem *ptr;

	ptr = root_a->next;
	while (ptr->next->root != 1)
	{
		if (ptr->nb > ptr->next->nb)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int		ft_get_index(t_elem *elem)
{
	int size;

	size = 0;
	while (elem->root == 0)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}

t_elem	*ft_get_min(t_elem *root_a)
{
	t_elem	*min;

	root_a = root_a->next;
	min = root_a;
	while (root_a->root != 1)
	{
		if (root_a->nb < min->nb)
			min = root_a;
		root_a = root_a->next;
	}
	return (min);
}

t_elem	*ft_get_max(t_elem *root_a)
{
	t_elem	*max;

	root_a = root_a->next;
	max = root_a;
	while (root_a->root != 1)
	{
		if (root_a->nb > max->nb)
			max = root_a;
		root_a = root_a->next;
	}
	return (max);
}
