/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_selection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:23:51 by conoel            #+#    #+#             */
/*   Updated: 2019/02/07 15:27:49 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_call(char *ft, t_elem *root_a, t_elem *root_b, int delay, t_elem *mark)
{
	if (ft_strcmp(ft, "ra") == 0)
	{
		write(1, "ra\n", 3);
		rotate(root_a);
	}
	else if (ft_strcmp(ft, "rra") == 0)
	{
		write(1, "rra\n ", 4);
		r_rotate(root_a);
	}
	else if (ft_strcmp(ft, "pa") == 0)
	{
		write(1, "pa\n", 3);
		push(root_a, root_b);
	}
	else if (ft_strcmp(ft, "pb") == 0)
	{
		write(1, "pb\n", 3);
		push(root_b, root_a);
	}
	if (delay != -1)
	{
		print_stack(root_a, root_b, ft, mark);
		usleep(SEC / delay);
	}
}

static void solve(t_elem *root_a, t_elem *root_b, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_a)->next);
	while (issort(root_a) == 0)
	{
		tmp = ft_get_max(root_a);
		index = ft_get_index(tmp);
		if (index >size / 2)
		{
			while ((root_a)->previous != tmp)
			{
				ft_call("rra", root_a, root_b, delay, tmp);
			}
		}
		else
			while ((root_a)->previous != tmp)
				ft_call("ra",root_a, root_b, delay, tmp);
		ft_call("pa", root_a, root_b, delay, 0);
		size--;
	}
	while ((root_b)->next != root_b)
		ft_call("pb", root_a, root_b, delay, 0);
	if (delay != -1)
	{
		print_stack(root_a, root_b, "  ", 0);
		usleep(SEC / delay);
	}
}

int				main(int argc, char **argv)
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
	if (argc > 2 && argv[argc - 1][0] == 'c')
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
