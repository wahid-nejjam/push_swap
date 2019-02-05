/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quick.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:58:23 by conoel            #+#    #+#             */
/*   Updated: 2019/02/05 20:12:56 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solve_a(t_elem *root_a, t_elem *root_b, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_a)->next);
	while (root_a->next != root_a)
	{
		tmp = ft_get_min(root_a);
		index = ft_get_index(tmp);
		if (index >size / 2)
		{
			while ((root_a)->previous != tmp)
			{
				exec_ft("rra", root_a, root_b, delay);
			}
		}
		else
			while ((root_a)->previous != tmp)
				exec_ft("ra", root_a, root_b, delay);
		exec_ft("pa", root_a, root_b, delay);
		size--;
	}
	if (delay != -1)
		print_stack(root_a, root_b, "", 0);
}

static void	solve_b(t_elem *root_a, t_elem *root_b, int delay)
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

static void cut_a(t_elem *root_a, t_elem *root_b, t_elem *start, int delay)
{
	int		mid_value;
	
	if (start->next->next == root_a)
		return ;
	mid_value = start->nb;
	while (ft_get_max(root_a)->nb >= mid_value && root_a->next != root_a)
	{
		if (root_a->previous->nb >= mid_value)
			exec_ft("pa", root_a, root_b, delay);
		else
			exec_ft("ra", root_a, root_b, delay);
	}
}

static void cut_b(t_elem *root_a, t_elem *root_b, t_elem *start, int delay)
{
	int		mid_value;

	if (start->next->next == root_b)
		return ;
	mid_value = start->nb;
	while (ft_get_min(root_b)->nb <= mid_value && root_b->next != root_b)
	{
		if (root_b->previous->nb <= mid_value)
			exec_ft("pb", root_a, root_b, delay);
		else
			exec_ft("rb", root_a, root_b, delay);
	}
}


static void		solve(t_elem *root_a, t_elem *root_b, int delay)
{
	t_elem	*mid;
	int		size;

	while (root_a->next != root_a)
	{
		mid = get_median(root_a);
		cut_a(root_a, root_b, mid, delay);
		if (heat_size(root_b) < 10)
			solve_a(root_a, root_b, delay);
	}
	size = heat_size(root_b);
	while (size > 40)
	{
		while (root_b->next != root_b)
		{
			mid = get_median(root_b);
			cut_b(root_a, root_b, mid, delay);
			if (heat_size(root_b) < 10)
				solve_b(root_a, root_b, delay);
		}
		while (root_a->next != root_a)
		{
			mid = get_median(root_a);
			cut_a(root_a, root_b, mid, delay);
			if (heat_size(root_b) < 10)
				solve_a(root_a, root_b, delay);
		}
		size /= 2;
	}
	solve_b(root_a, root_b, delay);
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
