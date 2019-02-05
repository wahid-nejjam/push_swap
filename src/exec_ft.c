/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 14:13:47 by conoel            #+#    #+#             */
/*   Updated: 2019/02/05 00:42:27 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	print(char *ft, t_elem *root_a, t_elem *root_b, int delay)
{
	write(1, ft, ft_strlen(ft));
	write(1, "\n", 1);
	if (delay != -1)
	{
		print_stack(root_a, root_b, ft, 0);
		usleep(SEC / delay);
	}
}

void		exec_ft(char *ft, t_elem *root_a, t_elem *root_b, int delay)
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
	print(ft, root_a, root_b, delay);
}
