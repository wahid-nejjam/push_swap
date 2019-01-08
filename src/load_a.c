/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:12:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 18:31:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem			*load_a(int argc, char **argv)
{
	size_t		i;
	t_elem	*root_a;
	t_elem	*tmp;

	i = 1;
	if (argc < 2)
		return (NULL);
	if (!(root_a = new(0, NULL, NULL, 1)))
		return (NULL);
	if (!(root_a->next = new(ft_atoi(argv[i]), root_a, root_a, 0)))
		return (NULL);
	root_a->previous = root_a->next;
	tmp = root_a->next;
	while (++i < (size_t)argc)
	{
		if (!(tmp = new(ft_atoi(argv[i]), root_a, tmp, 0)))
			return (NULL);
		tmp->previous->next = tmp;
	}
	root_a->previous = tmp;
	return (root_a);
}
