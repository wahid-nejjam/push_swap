/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:12:28 by conoel            #+#    #+#             */
/*   Updated: 2019/03/24 15:58:10 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		allocate_heap(t_elem *root_a, int **all)
{
	int		i;

	i = 0;
	if (!(*all = malloc(sizeof(int) * (heap_size(root_a) + 1))))
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
			{
				free(all);
				return (0);
			}
	}
	free(all);
	return (1);
}

static void		get_all(int argc, char **argv, t_elem *root_a, int visu)
{
	size_t	i;
	t_elem	*tmp;

	if (argc == 2 && visu)
		exit_(NULL);
	i = (argc == 2 || (argc == 3 && visu)) && ft_strchr(argv[1], ' ') ? -1 : 0;
	tmp = root_a;
	while (((argc == 3 && visu) || argc == 2) ? argv[++i] != NULL :
			++i < (size_t)argc)
	{
		if (argv[i][0] != 'c')
			if (!(tmp = new(ft_atoi_error(argv[i], root_a), tmp, root_a, 0)))
				return ;
		tmp->next->previous = tmp;
		root_a->next = tmp;
	}
	root_a->next = tmp;
}

t_elem			*load_a(int argc, char **argv)
{
	size_t	i;
	t_elem	*root_a;
	char	visu;

	visu = ((argv[argc - 1][0] == 'c')) ? 1 : 0;
	i = (argc == 2 || (argc == 3 && visu)) ? 0 : 1;
	argc < 2 ? exit(-1) : 0;
	(argc == 2 || (visu && argc == 3)) && ft_strchr(argv[1], ' ') ? argv =
		ft_strsplit(argv[1], ' ') : 0;
	if (!(root_a = new(666, NULL, NULL, 1)))
		return (NULL);
	get_all(argc, argv, root_a, visu);
	if (argc == 2 && argv[2] != NULL)
	{
		i = 0;
		while (argv[i] != 0)
			free(argv[i++]);
		free(argv);
	}
	if (check(root_a) == 0)
	{
		ft_free(root_a, NULL);
		return (NULL);
	}
	return (root_a);
}
