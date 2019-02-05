/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quick.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 18:30:29 by conoel            #+#    #+#             */
/*   Updated: 2019/02/05 19:08:01 by conoel           ###   ########.fr       */
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

t_elem	*ft_geti_max(t_elem *root, int index)
{
	t_elem	*max;

	root = root->previous;
	max = root->previous;
	if (root == root->previous)
		return (root);
	while (root->root != 1 && index-- >= 0)
	{
		if (root->nb > max->nb)
			max = root;
		root = root->previous;
	}
	return (max);
}

t_elem	*ft_geti_min(t_elem *root, int index)
{
	t_elem	*min;

	root = root->previous;
	min = root->previous;
	if (root == root->previous)
		return (root);
	while (root->root != 1 && index-- >= 0)
	{
		if (root->nb < min->nb)
			min = root;
		root = root->previous;
	}
	return (min);
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

void	insertsort(t_elem *root_a, t_elem *root_b, int size, int delay)
{
	int		index;
	t_elem	*max;
	t_elem	*min;
	t_elem	*tmp;

	min = root_b->previous;
	max = get_at_index(root_b, size);
	tmp = ft_geti_min(root_b, size);
	while (root_b->next != root_b && tmp != min && tmp != max)
	{
		tmp = ft_geti_min(root_b, size);
		index = ft_get_index(tmp);
		if (index > size / 2)
		{
			while ((root_b)->previous != tmp && tmp->previous != min)
			{
				exec_ft("rrb", root_a, root_b, delay);
				printf("insertsort\n");
			}
		}
		else
			while ((root_b)->previous != tmp && tmp->next != min)
			{
				exec_ft("rb", root_a, root_b, delay);
				printf("insert_sort\n");
			}
		exec_ft("pb", root_a, root_b, delay);
		printf("insertsort pushing\n");
	}
	if (delay != -1)
		print_stack(root_a, root_b, "", 0);
}

void		solve_once(t_elem *root_a, t_elem *root_b, int size, int delay)
{
	t_elem	*mid;
	int		max;

	max = size;
	mid = get_median(size > 0 ? root_a : root_b);
	while (ft_geti_max(size > 0 ? root_a : root_b, size)->nb > mid->nb && size)
	{
		if ((size > 0 ? root_a : root_b)->previous->nb > mid->nb)
		{
			exec_ft(size > 0 ? "pa" : "pb", root_a, root_b, delay);
			size > 0 ? max-- : max++;
		}
		else
			exec_ft(size > 0 ? "ra" : "rb", root_a, root_b, delay);
		printf("solveonce %d", size);
	}
}
