/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:12:28 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 17:51:31 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		allocate_heap(t_elem *root_a, int **all)
{
	int		i;

	i = 0;
	if (!(*all = malloc_garbage(sizeof(int) * (heap_size(root_a) + 1))))
		exit_(NULL);
	root_a = root_a->next;
	while (!root_a->root)
	{
		(*all)[i++] = root_a->nb;
		root_a = root_a->next;
	}
	return (i);
}

static int		check(t_elem *root_a)
{
	int		*all;
	int		i;
	int		j;
	int		k;

	i = allocate_heap(root_a, &all);
	j = -1;
	while (++j < i)
	{
		k = -1;
		while (++k < i)
			if (all[k] == all[j] && k != j)
				return (0);
	}
	return (1);
}

static void		get_all(int argc, char **argv, t_elem *root_a)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = root_a;
	while (++i < argc)
	{
		if (argv[i][0] != 'c' || argc - 1 != i)
			if (!(tmp = new(ft_atoi_error(argv[i]), tmp, root_a, 0)))
				return ;
		tmp->next->previous = tmp;
		root_a->next = tmp;
	}
	root_a->next = tmp;
}

t_elem			*load_a(int argc, char **argv)
{
	t_elem	*root_a;
	char	visu;

	if (argc < 2)
		return (0);
	visu = (argv[argc - 1][0] == 'c') ? 1 : 0;
	if (argc == 2 && visu)
		return (0);
	if (!(root_a = new(666, NULL, NULL, 1)))
		return (NULL);
	get_all(argc, argv, root_a);
	if (check(root_a) == 0)
		return (NULL);
	return (root_a);
}
