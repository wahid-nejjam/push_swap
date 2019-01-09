/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/09 19:19:31 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

static void	is_sort(t_elem *root_a, t_elem *root_b)
{
	t_elem	*tmp;

	tmp = root_a->next;
	while (!tmp->next->root)
	{
		if (tmp->nb > tmp->next->nb)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	if (root_b->previous != root_b || root_b->next != root_b) 
	{
		write(1, "KO (B not emptied)\n", 19);
		return ;
	}
	write(1, "OK\n", 3);
}

static int	exec_ft(char *ft, t_elem **root_a, t_elem **root_b)
{
	if (ft_memcmp(ft, "sa\n", 3) == 0 || ft_memcmp(ft, "sa \n", 4) == 0)
		swap(*root_a);
	else if (ft_memcmp(ft, "sb\n", 3) == 0 || ft_memcmp(ft, "sb \n", 4) == 0)
		swap(*root_b);
	else if (ft_memcmp(ft, "ss\n", 3) == 0 || ft_memcmp(ft, "ss \n", 4) == 0)
		double_swap(*root_a, *root_b);
	else if (ft_memcmp(ft, "pa\n", 3) == 0 || ft_memcmp(ft, "pa \n", 4) == 0)
		push(*root_a, *root_b);
	else if (ft_memcmp(ft, "pb\n", 3) == 0 || ft_memcmp(ft, "pb \n", 4) == 0)
		push(*root_b, *root_a);
	else if (ft_memcmp(ft, "ra\n", 3) == 0 || ft_memcmp(ft, "ra \n", 4) == 0)
		rotate(root_a);
	else if (ft_memcmp(ft, "rb\n", 3) == 0 || ft_memcmp(ft, "rb \n", 4) == 0)
		rotate(root_b);
	else if (ft_memcmp(ft, "rr\n", 3) == 0 || ft_memcmp(ft, "rr \n", 4) == 0)
		double_rotate(root_a, root_b);
	else if (ft_memcmp(ft, "rra\n", 4) == 0)
		r_rotate(root_a);
	else if (ft_memcmp(ft, "rrb\n", 4) == 0)
		r_rotate(root_b);
	else if (ft_memcmp(ft, "rrr\n", 4) == 0)
		double_r_rotate(root_a, root_b);
	else 
		return (-1);
	return (1);
}

static int solve(t_elem *root_a, t_elem *root_b)
{
	char line[5];

	ft_bzero(line, 5);
	while (read(0, line, 4))
	{
		if (exec_ft(line, &root_a, &root_b) == -1)
		{
			write(2, "Learn how to type, dumbass.\n", 28);
			return (0);
		}
		ft_bzero(line, 5);
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
	ft_free(root_a, root_b);
	return (0);
}