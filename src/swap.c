/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:02 by conoel            #+#    #+#             */
/*   Updated: 2019/02/03 17:30:07 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		swap(t_elem *root)
{
	int			tmp;

	if (root->next == root)
		return ;
	tmp = root->previous->nb;
	root->previous->nb = root->previous->previous->nb;
	root->previous->previous->nb = tmp;
}

void		double_swap(t_elem *root_a, t_elem *root_b)
{
	swap(root_a);
	swap(root_b);
}
