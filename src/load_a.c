/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:12:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 18:44:46 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem			*load_a(int argc, char **argv)
{
	int		i;
	t_elem	*first_a;
	t_elem	*last_a;
	t_elem	*tmp;

	i = 1;
	if (argc < 2)
		return (NULL);
	if (!(last_a = malloc(sizeof(*last_a))))
		return (NULL);
	last_a->nb = ft_atoi(argv[i]);
	last_a->next = NULL;
	last_a->previous = NULL;
	first_a = last_a;
	while (++i < argc)
	{
		if (!(tmp = malloc(sizeof(*tmp))))
			return (NULL);
		tmp->nb = ft_atoi(argv[i]);
		tmp->previous = last_a;
		tmp->next = NULL;
		last_a->next = tmp;
		last_a = tmp;
	}
	last_a->next = first_a;
	first_a->previous = last_a;
	return (last_a);
}
