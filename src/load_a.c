/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:12:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 17:37:50 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem			*load_a(int argc, char	**argv)
{
	int		i;
	t_elem  *last_a;
	t_elem	*tmp;

	i = 0;
	if (argc < 2)
		return (NULL);
	if (!(last_a = malloc(sizeof last_a)))
		return (NULL);
	last_a->nb = ft_atoi(argv[i]);
	while (i++ < argc)
	{
		if (!(last_a = malloc(sizeof last_a)))
			return (NULL);
		last_a->nb = ft_atoi(argv[i]);
		last_a->next = tmp;
		tmp->previous = last_a;
		last_a = tmp;
	}
}