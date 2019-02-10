/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:05:26 by conoel            #+#    #+#             */
/*   Updated: 2019/02/09 21:16:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (argc > 2 && argv[argc - 1][0] == 'c')
	{
		delay = ft_atoi(&(argv[argc - 1][1]));
	}
	else
		delay = -1;
	if (root_a == NULL)
		write(2, "THERE IS NO LIST NIGGA\n", 24);
	else
		solve_list(root_a, root_b, delay);
	ft_free(root_a, root_b);
}
