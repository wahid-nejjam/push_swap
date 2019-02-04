/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   push_swap.c	:+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: conoel <conoel@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2019/02/02 18:15:24 by conoel	#+#	#+#	 */
/*   Updated: 2019/02/03 17:18:54 by conoel	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	solve_b(t_elem *root_a, t_elem *root_b, int delay)
{
	int		size;
	int		index;
	t_elem	*tmp;

	size = ft_get_index((root_b)->next);
	while (root_b->next != root_b)
	{
		tmp = ft_get_min(root_b);
		index = ft_get_index(tmp);
		if (index >size / 2)
		{
			while ((root_b)->previous != tmp)
			{
				exec_ft("rrb", root_a, root_b, delay);
			}
		}
		else
			while ((root_b)->previous != tmp)
				exec_ft("rb", root_a, root_b, delay);
		exec_ft("pb", root_a, root_b, delay);
		size--;
	}
	if (delay != -1)
		print_stack(root_a, root_b, "", 0);
}

static void cut_a(t_elem *root_a, t_elem *root_b, t_elem *start, int delay)
{
	t_elem	*max;
	int		mid_value;
	
	if (start->next->next == root_a)
		return ;
	max = ft_get_max(start);
	mid_value = max->nb / 2;
	while (ft_get_max(root_a)->nb >= mid_value && root_a->next != root_a)
	{
		if (root_a->previous->nb >= mid_value)
			exec_ft("pa", root_a, root_b, delay);
		else
			exec_ft("ra", root_a, root_b, delay);
	}
}

static void cut_b(t_elem *root_a, t_elem *root_b, t_elem *start, int delay)
{
	t_elem	*max;
	int		mid_value;
	
	if (start->next->next == root_b)
		return ;
	max = ft_get_max(start);
	mid_value = max->nb / 2;
	while (ft_get_max(root_b)->nb >= mid_value && root_b->next != root_b)
	{
		if (root_b->previous->nb >= mid_value)
			exec_ft("pb", root_a, root_b, delay);
		else
			exec_ft("rb", root_a, root_b, delay);
	}
}

static void	solve(t_elem *root_a, t_elem *root_b, int delay)
{
	t_elem	*max;

	while (root_a->next != root_a)
	{
		max = ft_get_max(root_a);
		cut_a(root_a, root_b, max, delay);
		max = ft_get_max(root_b);
		cut_b(root_a, root_b, max, delay);

	}
	solve_b(root_a, root_b, delay);
}

/*static void	solve(t_elem *root_a, t_elem *root_b, int delay)
{
	t_elem	*max;
	int		mid_value;

	while (!(issort(root_a) && ft_get_min(root_b)->nb > ft_get_max(root_a)->nb) && root_a->next != root_a)
	{
		max = ft_get_max(root_a);
		mid_value = max->nb / 2;
		while (ft_get_max(root_a)->nb >= mid_value && root_a->next != root_a)
		{
			if (root_a->previous->nb >= mid_value)
				exec_ft("pa", root_a, root_b, delay);
			else
				exec_ft("ra", root_a, root_b, delay);
		}
	}
	solve_b(root_a, root_b, delay);
}*/

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
	if (argc > 2 && argv[argc - 1][0] == '-')
	{
		delay = ft_atoi(&(argv[argc - 1][1]));
	}
	else
		delay = -1;
	if (root_a == NULL)
		write(2, "THERE IS NO LIST NIGGA\n", 24);
	else
		solve(root_a, root_b, delay);
	ft_free(root_a, root_b);
	return (0);
}
