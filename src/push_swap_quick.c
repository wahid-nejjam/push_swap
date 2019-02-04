/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:58:23 by conoel            #+#    #+#             */
/*   Updated: 2019/02/04 23:12:28 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	insertsort_a_to_b(t_elem *root_a, t_elem *root_b, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_b)->next);
	while (root_b->next != root_b)
	{
		tmp = ft_get_min(root_b);
		index = ft_get_index(tmp);
		if (index >size / 2)
		{
			while ((root_b)->previous != tmp)
			{
				exec_ft("rrb", root_a, root_b, delay);
			}
		}
		else
			while ((root_b)->previous != tmp)
				exec_ft("rb", root_a, root_b, delay);
		exec_ft("pb", root_a, root_b, delay);
		size--;
	}
	if (delay != -1)
		print_stack(root_a, root_b, "", 0);
}

static void		solve_once(t_elem *root_a, t_elem *root_b, int size, int delay)
{
	t_elem	*mid;
	int		max;

	max = size;
	mid = get_median(size > 0 ? root_a : root_b);
	printf("mid %d top_nb %d iter %d size %d getimax %d\n", mid->nb, root_a->previous->nb, max, size, ft_geti_max(mid, size)->nb);
	while (ft_geti_max(root_a, size)->nb > mid->nb && max-- >= 0)
	{
		if (root_a->previous->nb > mid->nb)
			exec_ft(size > 0 ? "pa" : "pb", root_a, root_b, delay);
		else
			exec_ft(size > 0 ? "ra" : "sb", root_a, root_b, delay);
		printf("mid %d nb %d iter %d size %d\n", mid->nb, root_a->previous->nb, max, size);
	}
}

static void		solve(t_elem *root_a, t_elem *root_b, int size, int delay)
{
	if (size >= -15 && size <= 15)
	{
		solve_once(root_a, root_b, size, delay);
		solve_once(root_a, root_b, size, delay);
		insertsort_a_to_b(root_a, root_b, delay);
	}
	else
	{
		solve_once(root_a, root_b, size, delay);
		solve(root_a, root_b, size / 2, delay);
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
		solve(root_a, root_b, heat_size(root_a), delay);
	ft_free(root_a, root_b);
	return (0);
}
