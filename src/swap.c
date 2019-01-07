/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:02 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 17:05:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		sa(t_elem *last_a)
{
	t_elem		*second;
	int			tmp;

	second = last_a->previous;
	tmp = last_a->nb;
	last_a->nb = second->nb;
	second->nb = tmp;
}

void		sb(t_elem *last_b)
{
	t_elem		*second;
	int			tmp;

	second = last_b->previous;
	tmp = last_b->nb;
	last_b->nb = second->nb;
	second->nb = tmp;
}

void		ss(t_elem *last_a, t_elem *last_b)
{
	t_elem		*second;
	int			tmp;

	second = last_a->previous;
	tmp = last_a->nb;
	last_a->nb = second->nb;
	second->nb = tmp;
	second = last_b->previous;
	tmp = last_b->nb;
	last_b->nb = second->nb;
	second->nb = tmp;
}