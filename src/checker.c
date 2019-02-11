/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:58 by conoel            #+#    #+#             */
/*   Updated: 2019/02/11 17:34:26 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	is_sort(t_elem *root_a, t_elem *root_b)
{
	t_elem	*tmp;

	tmp = root_a->next;
	while (!tmp->next->root)
	{
		if (tmp->nb > tmp->next->nb)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	if (root_b->previous != root_b || root_b->next != root_b)
	{
		write(1, "KO (B not emptied)\n", 19);
		return ;
	}
	write(1, "OK\n", 3);
	return ;
}

static void	print(char *ft, t_elem *root_a, t_elem *root_b, int delay)
{
	if (delay != -1)
	{
		print_stack(root_a, root_b, ft, 0);
		usleep(SEC / delay);
	}
}

static int	exec_ft_checker(char *ft, t_elem *root_a, t_elem *root_b, int delay)
{
	if (ft_strcmp(ft, "sa") == 0)
		swap(root_a);
	else if (ft_strcmp(ft, "sb") == 0)
		swap(root_b);
	else if (ft_strcmp(ft, "ss") == 0)
		double_swap(root_a, root_b);
	else if (ft_strcmp(ft, "pa") == 0)
		push(root_a, root_b);
	else if (ft_strcmp(ft, "pb") == 0)
		push(root_b, root_a);
	else if (ft_strcmp(ft, "ra") == 0)
		rotate(root_a);
	else if (ft_strcmp(ft, "rb") == 0)
		rotate(root_b);
	else if (ft_strcmp(ft, "rr") == 0)
		double_rotate(root_a, root_b);
	else if (ft_strcmp(ft, "rra") == 0)
		r_rotate(root_a);
	else if (ft_strcmp(ft, "rrb") == 0)
		r_rotate(root_b);
	else if (ft_strcmp(ft, "rrr") == 0)
		double_r_rotate(root_a, root_b);
	else
		return (-1);
	print(ft, root_a, root_b, delay);
	return (1);
}

static int	solve(t_elem *root_a, t_elem *root_b, int delay)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line, '\n'))
	{
		if (exec_ft_checker(line, root_a, root_b, delay) == -1)
			exit_free(NULL, 1, line);
		free(line);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_elem	*root_a;
	t_elem	*root_b;
	int		delay;

	if (!(root_a = load_a(argc, argv)))
		exit_("THERE IS NO LIST NIGGA\n");
	if (!(root_b = new(0, NULL, NULL, 1)))
	{
		ft_free(root_a, root_b);
		exit_(NULL);
	}
	root_b->next = root_b;
	root_b->previous = root_b;
	if (argc > 2 && argv[argc - 1][0] == 'c')
	{
		delay = ft_atoi(&(argv[argc - 1][1]));
	}
	else
		delay = -1;
	if (solve(root_a, root_b, delay))
		is_sort(root_a, root_b);
	ft_free(root_a, root_b);
	return (0);
}
