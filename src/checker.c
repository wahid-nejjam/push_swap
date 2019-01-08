/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 12:48:26 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

static void	is_sort(t_elem *last_a, t_elem *last_b)
{
	t_elem	*mem;

	mem = last_a;
	while (mem != last_a)
	{
		if (last_a->nb > last_a->previous->nb)
		{
			write(1, "KO\n", 3);
			return ;
		}
		last_a = last_a->previous;
	}
	if (last_b->previous != last_b || last_b->next != last_b) 
	{
		write(1, "KO\n", 3);
		return ;
	}
	write(1, "OK\n", 1);
}

static int	exec_ft(char *ft, t_elem **last_a, t_elem **last_b)
{
	if (ft_strcmp(ft, "sa\n") == 0)
		swap(*last_a);
	else if (ft_strcmp(ft, "sb\n") == 0)
		swap(*last_b);
	else if (ft_strcmp(ft, "ss\n") == 0)
		double_swap(*last_a, *last_b);
	else if (ft_strcmp(ft, "ra\n") == 0)
		*last_a = (*last_a)->next;
	else if (ft_strcmp(ft, "rb\n") == 0)
		*last_b = (*last_b)->next;
	else if (ft_strcmp(ft, "rr\n") == 0)
		double_rotate(last_a, last_b);
	else 
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_elem	*last_a;
	t_elem	*last_b;
	char	line[4];

	line[3] = '\0';
	last_a = load_a(argc, argv);
	if (!(last_b = malloc(sizeof(*last_b))))
		return (-1);
	last_b->nb = 0;
	last_b->next = last_b;
	last_b->previous = last_b;
	if (last_a == NULL)
	{
		write(2, "THAT DOESNT WORKED NIGGA\n", 26);
		return (-1);
	}
	while (read(1, line, 3))
	{
		if (exec_ft(line, &last_a, &last_b) == -1)
		{
			write(2, "Learn how to type, dumbass.\n", 28);
			return (-1);
		}
	}
	is_sort(last_a, last_b);
	return (0);
}