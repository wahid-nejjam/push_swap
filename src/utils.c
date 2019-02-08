/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:43:24 by conoel            #+#    #+#             */
/*   Updated: 2019/02/07 16:09:53 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		issort(t_elem *root)
{
	t_elem	*tmp;

	if (root->next == root)
		return (1);
	tmp = root->next;
	while (!tmp->next->root)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
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

t_elem	*ft_get_min(t_elem *root)
{
	t_elem	*min;

	root = root->next;
	min = root;
	if (root == root->next)
		return (root);
	while (root->root != 1)
	{
		if (root->nb < min->nb)
			min = root;
		root = root->next;
	}
	return (min);
}

t_elem	*ft_get_max(t_elem *root)
{
	t_elem	*max;

	root = root->next;
	max = root;
	if (root == root->next)
		return (root);
	while (root->root != 1)
	{
		if (root->nb > max->nb)
			max = root;
		root = root->next;
	}
	return (max);
}

int		heap_size(t_elem *root)
{	
	int	 i;

	i = 0;
	while (!root->next->root)
	{
		i++;
		root = root->next;
	}
	return (i);
}
