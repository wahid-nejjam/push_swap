/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:30:29 by conoel            #+#    #+#             */
/*   Updated: 2019/02/04 23:11:00 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*ft_geti_max(t_elem *root, int index)
{
	t_elem	*max;

	root = root->next;
	max = root->next;
	if (root == root->next)
		return (root);
	while (root->root != 1 && index-- >= 0)
	{
		printf("		*nb: %d max: %d iter: %d\n", root->nb, max->nb, index);
		if (root->nb > max->nb)
			max = root;
		root = root->next;
	}
	return (max);
}

t_elem	*get_median(t_elem *root)
{
	t_elem	*median;
	int		size;
	int		i;

	i = 0;
	median = root->next;
	size = heat_size(root);
	while (i < size / 2)
	{
		median = median->next;
		i++;
	}
	return (median);
}

int		heat_size(t_elem *root)
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
