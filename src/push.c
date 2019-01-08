/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:57:07 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 22:12:33 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_elem *root1, t_elem *root2)
{
	if (root1->next == root1)
		return ;
	root1->previous->next = root2;
	root1->previous->previous = root2->previous;
	root2->previous->next = root1->previous;
	root2->previous = root1->previous;
	root1->previous->previous->next = root1;
	root1->previous = root1->previous->previous;
}