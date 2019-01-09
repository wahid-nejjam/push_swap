/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:13 by conoel            #+#    #+#             */
/*   Updated: 2019/01/09 16:17:53 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solve(t_elem *root_a, t_elem *root_b)
{
	t_elem	*ptr;
	t_elem	*save;
	int		min;

	ptr = root_a->next;
	while (root_a->next != root_a)
	{
		ptr = root_a->next;
		min = ptr->nb;
		while(ptr != root_a)
		{
			if (ptr->nb < min)
			{
				min = ptr->nb;
				save = ptr;
			}
			ptr = ptr->next;
		}
		while(root_a->previous->nb != min)
		{
			write(1, "ra\n", 3);
			rotate(&root_a);
			//print_stack(root_a, root_b);
		}
		write(1, "pa\n", 3);
		push(root_a, root_b);
		//print_stack(root_a, root_b);
	}
	while (root_b->next != root_b)
	{
		push(root_b, root_a);
		//print_stack(root_a, root_b);
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
		solve(root_a, root_b);
	ft_free(root_a, root_b);
	return (0);
}