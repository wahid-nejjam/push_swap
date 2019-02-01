
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:12:55 by conoel            #+#    #+#             */
/*   Updated: 2019/02/01 18:51:49 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem			*load_a(int argc, char **argv)
{
	size_t	i;
	t_elem	*root_a;
	t_elem	*tmp;

	i = argc == 2 ? 0 : 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		argv = ft_strsplit(argv[1], ' ');
	if (!(root_a = new(0, NULL, NULL, 1)))
		return (NULL);
	if (!(root_a->next = new(ft_atoi(argv[i]), root_a, root_a, 0)))
		return (NULL);
	root_a->previous = root_a->next;
	tmp = root_a->next;
	while (argc != 2 ? ++i < (size_t)argc : argv[++i] != 0)
	{
		if (!(tmp = new(ft_atoi(argv[i]), root_a, tmp, 0)))
			return (NULL);
		tmp->previous->next = tmp;
	}
	root_a->previous = tmp;
	if (argc == 2)
		free(argv);
	return (root_a);
}
