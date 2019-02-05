/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:12:28 by conoel            #+#    #+#             */
/*   Updated: 2019/02/04 14:16:53 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		get_all(int argc, char **argv, t_elem *root_a)
{
	size_t	i;
	t_elem	*tmp;

	i = argc == 2 ? 0 : 1;
	tmp = root_a->next;
	while (argc != 2 ? ++i < (size_t)argc : argv[++i] != 0)
	{
		if (argv[i][0] != '-')
			if (!(tmp = new(ft_atoi(argv[i]), root_a, tmp, 0)))
				return ;
		tmp->previous->next = tmp;
	}
	root_a->previous = tmp;
}

t_elem			*load_a(int argc, char **argv)
{
	size_t	i;
	t_elem	*root_a;

	i = argc == 2 ? 0 : 1;
	if (argc < 2)
		return (NULL);
	if (argc == 2 || (argc == 3 && argv[2][0] == '-'))
		argv = ft_strsplit(argv[1], ' ');
	if (!(root_a = new(0, NULL, NULL, 1)))
		return (NULL);
	if (!(root_a->next = new(ft_atoi(argv[i]), root_a, root_a, 0)))
		return (NULL);
	root_a->previous = root_a->next;
	get_all(argc, argv, root_a);
	if (argc == 2)
		free(argv);
	return (root_a);
}
