/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_random.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:49:55 by conoel            #+#    #+#             */
/*   Updated: 2019/02/02 18:17:01 by conoel           ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;
	int		delay;

	root_a = load_a(argc, argv);
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		write(2, "Allocation error :(", 21);
		ft_free(root_a, root_b);
		return (-1);
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (argc > 2 && argv[argc - 1][0] == '-')
	{
		delay = ft_atoi(&(argv[argc - 1][1]));
	}
	else
		delay = -1;
	if (root_a == NULL)
		write(2, "THERE IS NO LIST NIGGA\n", 24);
	else
		solve(root_a, root_b, delay);
	ft_free(root_a, root_b);
	return (0);
}
