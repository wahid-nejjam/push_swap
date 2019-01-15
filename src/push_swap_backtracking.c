/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_backtracking.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:36:19 by conoel            #+#    #+#             */
/*   Updated: 2019/01/15 13:49:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"




static void	solve(t_elem *root_a, t_elem *root_b)
{
	s_ft *start;

	start = solving(&root_a, &root_b);

}

int			main(int argc, char **argv)
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
