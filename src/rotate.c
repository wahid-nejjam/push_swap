/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:42:31 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 18:58:11 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		rotate(t_elem **root)
{
	(*root)->nb = (*root)->previous->nb;
	(*root)->root = 0;
	(*root)->previous->root = 1;
	*root = (*root)->previous;
}

void		double_rotate(t_elem **root_a, t_elem **root_b)
{
	(*root_a)->nb = (*root_a)->previous->nb;
	(*root_a)->root = 0;
	(*root_a)->previous->root = 1;
	*root_a = (*root_a)->previous;
	(*root_b)->nb = (*root_b)->previous->nb;
	(*root_b)->root = 0;
	(*root_b)->previous->root = 1;
	*root_b = (*root_b)->previous;
}

void		r_rotate(t_elem **root)
{
	(*root)->nb = (*root)->next->nb;
	(*root)->root = 0;
	(*root)->next->root = 1;
	*root = (*root)->next;
}

void		double_r_rotate(t_elem **root_a, t_elem **root_b)
{
	(*root_a)->nb = (*root_a)->next->nb;
	(*root_a)->root = 0;
	(*root_a)->next->root = 1;
	*root_a = (*root_a)->next;
	(*root_b)->nb = (*root_b)->next->nb;
	(*root_b)->root = 0;
	(*root_b)->next->root = 1;
	*root_b = (*root_b)->next;
}
