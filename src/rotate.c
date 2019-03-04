/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:42:31 by conoel            #+#    #+#             */
/*   Updated: 2019/03/04 12:07:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		double_rotate(t_elem *root_a, t_elem *root_b)
{
	rotate(root_a);
	rotate(root_b);
}

void		rotate(t_elem *root)
{
	t_elem	*top;
	t_elem	*bottom;
	t_elem	*tmp;

	if (root->next == root)
		return ;
	tmp = root->previous;
	top = root->next;
	bottom = tmp->previous;
	top->previous = tmp;
	bottom->next = root;
	root->next = tmp;
	root->previous = bottom;
	tmp->next = top;
	tmp->previous = root;
}

void		double_r_rotate(t_elem *root_a, t_elem *root_b)
{
	r_rotate(root_a);
	r_rotate(root_b);
}

void		r_rotate(t_elem *root)
{
	t_elem	*top;
	t_elem	*bottom;
	t_elem	*tmp;

	if (root->next == root)
		return ;
	tmp = root->next;
	bottom = root->previous;
	top = tmp->next;
	top->previous = root;
	bottom->next = tmp;
	root->next = top;
	root->previous = tmp;
	tmp->next = root;
	tmp->previous = bottom;
}
