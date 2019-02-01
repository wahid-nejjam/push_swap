/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:58 by conoel            #+#    #+#             */
/*   Updated: 2019/02/01 05:56:19 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	is_sort(t_elem *root_a, t_elem *root_b)
{
	t_elem	*tmp;

	tmp = root_a->next;
	while (!tmp->next->root)
	{
		if (tmp->nb > tmp->next->nb)
		{
			write(1, "KO\n", 3);
			ft_free(root_a, root_b);
			return ;
		}
		tmp = tmp->next;
	}
	if (root_b->previous != root_b || root_b->next != root_b)
	{
		write(1, "KO (B not emptied)\n", 19);
		ft_free(root_a, root_b);
		return ;
	}
	write(1, "OK\n", 3);
	ft_free(root_a, root_b);
	return ;
}

static int	exec_ft(char *ft, t_elem **root_a, t_elem **root_b)
{
	if (ft_memcmp(ft, "sa", 3) == 0)
		swap(*root_a);
	else if (ft_memcmp(ft, "sb", 3) == 0)
		swap(*root_b);
	else if (ft_memcmp(ft, "ss", 3) == 0)
		double_swap(*root_a, *root_b);
	else if (ft_memcmp(ft, "pa", 3) == 0)
		push(*root_a, *root_b);
	else if (ft_memcmp(ft, "pb", 3) == 0)
		push(*root_b, *root_a);
	else if (ft_memcmp(ft, "ra", 3) == 0)
		rotate(root_a);
	else if (ft_memcmp(ft, "rb", 3) == 0)
		rotate(root_b);
	else if (ft_memcmp(ft, "rr", 3) == 0)
		double_rotate(root_a, root_b);
	else if (ft_memcmp(ft, "rra", 4) == 0)
		r_rotate(root_a);
	else if (ft_memcmp(ft, "rrb", 4) == 0)
		r_rotate(root_b);
	else if (ft_memcmp(ft, "rrr", 4) == 0)
		double_r_rotate(root_a, root_b);
	else
		return (-1);
	return (1);
}

static int	solve(t_elem *root_a, t_elem *root_b)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line, '\n'))
	{
		if (exec_ft(line, &root_a, &root_b) == -1)
		{
			write(2, "Learn how to type, dumbass.\n", 28);
			return (0);
		}
		free(line);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;

	root_a = load_a(argc, argv);
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		write(2, "Allocation error :(\n", 21);
		ft_free(root_a, root_b);
		return (-1);
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (root_a == NULL)
		write(2, "THERE IS NO LIST NIGGA\n", 24);
	else
	{
		if (solve(root_a, root_b))
			is_sort(root_a, root_b);
	}
	return (0);
}
