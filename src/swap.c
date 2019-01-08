/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:02 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 19:07:38 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		swap(t_elem *root)
{
	int			tmp;

	tmp = root->previous->nb;
	root->previous->nb = root->previous->previous->nb;
	root->previous->previous->nb = tmp;
}

void		double_swap(t_elem *root_a, t_elem *root_b)
{
	int			tmp;

	tmp = root_a->previous->nb;
	root_a->previous->nb = root_a->previous->previous->nb;
	root_a->previous->previous->nb = tmp;
	tmp = root_b->previous->nb;
	root_b->previous->nb = root_b->previous->previous->nb;
	root_b->previous->previous->nb = tmp;
}
