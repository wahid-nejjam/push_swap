/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:49:55 by conoel            #+#    #+#             */
/*   Updated: 2019/02/09 20:22:27 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <time.h>

static void	solve(t_elem *root_a, t_elem *root_b, int delay)
{
	int		is_sort;
	int		nb;

	srand(time(NULL));
	is_sort = issort(root_a);
	while (!is_sort)
	{
		nb = rand() % 3;
		if (nb == 0)
			exec_ft("sa", root_a, root_b, delay);
		else if (nb == 1)
			exec_ft("ra", root_a, root_b, delay);
		else if (nb == 2)
			exec_ft("rra", root_a, root_b, delay);
		is_sort = issort(root_a);
	}
}
