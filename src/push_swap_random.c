/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_random.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:49:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/09 19:04:21 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <time.h>

static int	issort(t_elem *root_a)
{
	t_elem *ptr;
	ptr = root_a->next;
	while (ptr->next->root != 1)
	{
		if (ptr->nb > ptr->next->nb)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

static void	solve(t_elem *root_a)
{
	int		is_sort;
	int		nb;

	srand(time(NULL));
	is_sort = issort(root_a);
	while(!is_sort)
	{
		nb = rand() % 3;
		if (nb == 0)
		{
			write(1, "sa \n", 4);
			swap(root_a);
		}
		else if (nb == 1)
		{
			write(1, "ra \n", 4);
			rotate(&root_a);
		}
		else if (nb == 2)
		{
			write(1, "rra\n", 4);			
			r_rotate(&root_a);
		}
		is_sort = issort(root_a);
	}
}

int		main(int argc, char**argv)
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
		solve(root_a);
	ft_free(root_a, root_b);
	return (0);
}