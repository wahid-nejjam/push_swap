/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:58:23 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 16:36:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(int delay, t_elem *root_a, t_elem *root_b)
{
	if (heap_size(root_a) <= 3)
		small_sort(root_a, root_b, delay);
	else if (heap_size(root_a) < 20)
		medium_sort(root_a, root_b, delay);
	else if (heap_size(root_a) <= 200)
		long_sort(root_a, root_b, delay);
	else
		very_long_sort(root_a, root_b, delay);
}

int			main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;
	int		delay;

	if (!(root_a = load_a(argc, argv)))
	{
		malloc_garbage(0);
		return (return_(NULL));
	}
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		malloc_garbage(0);
		return (return_(NULL));
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (argc > 2 && argv[argc - 1][0] == 'c')
		delay = ft_atoi(&(argv[argc - 1][1]));
	else
		delay = -1;
	sort(delay, root_a, root_b);
	malloc_garbage(0);
	return (1);
}
