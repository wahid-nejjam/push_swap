/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:23:51 by conoel            #+#    #+#             */
/*   Updated: 2019/01/15 12:47:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	ft_call(char *ft, t_elem **root_a, t_elem **root_b)
{
	if (ft_strcmp(ft, "ra") == 0)
	{
		write(1, "ra \n", 4);
		rotate(root_a);
	}
	else if (ft_strcmp(ft, "rra") == 0)
	{
		write(1, "rra\n ", 4);
		r_rotate(root_a);
	}
	else if (ft_strcmp(ft, "pa") == 0)
	{
		write(1, "pa \n", 4);
		push(*root_a, *root_b);
	}
	else if (ft_strcmp(ft, "pb") == 0)
	{
		write(1, "pb \n", 4);
		push(*root_b, *root_a);
	}
}

static void		ft_splitstack(t_elem **root_a, t_elem **root_b)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((*root_a)->next);
	while (issort(*root_a) == 0)
	{
		tmp = ft_get_max(*root_a);
		index = ft_get_index(tmp);
		if (index >= size / 2)
		{
			while ((*root_a)->previous != tmp)
				ft_call("ra", root_a, root_b);
		}
		else if (index < size / 2)
			while ((*root_a)->previous != tmp)
				ft_call("rra",root_a, root_b);
		ft_call("pa", root_a, root_b);
		size--;
	}
	while ((*root_b)->next != *root_b)
		ft_call("pb", root_a, root_b);
}

static void solve(t_elem **root_a, t_elem **root_b)
{
	ft_splitstack(root_a, root_b);
}

int				main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;
	char	line[5];

	ft_bzero(line, 5);
	root_a = load_a(argc, argv);
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		write(2, "Allocation error :(", 21);
		ft_free(root_a, root_b);
		return (-1);
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (root_a == NULL)
		write(2, "THERE IS NO LIST NIGGA\n", 24);
	else
		solve(&root_a, &root_b);
	//print_stack(root_a, root_b);
	ft_free(root_a, root_b);
	return (0);
}
