/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:30:29 by conoel            #+#    #+#             */
/*   Updated: 2019/02/07 18:12:30 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*get_at_index(t_elem *root, int index)
{
	t_elem *tmp;

	tmp = root->next;
	while(index-- && root != root->next && !tmp->next->root)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

int		get_median(t_elem *root)
{
	int		median;
	int		min;
	int		max;

	min = ft_get_min(root)->nb;
	max = ft_get_max(root)->nb;
	median = ((max - min) / 2) + min;
	return (median);
}

int		not_sort(t_elem	*root)
{
	int 	ret;
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
