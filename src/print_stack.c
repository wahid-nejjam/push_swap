/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:59:12 by conoel            #+#    #+#             */
/*   Updated: 2019/01/09 13:27:03 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		print_stack(t_elem *root_a, t_elem *root_b)
{
	t_elem	*tmpa;
	t_elem	*tmpb;
	
	tmpb = root_b->previous;
	tmpa = root_a->previous;
	write(1, "Liste_a\n", 9);
	while (!tmpa->root || !tmpb->root)
	{
		printf(tmpa->root ? "   " : "|%d|", tmpa->nb);
		tmpa = (tmpa->root ? tmpa : tmpa->previous);
		printf(tmpb->root ? "\n" : "|%d|\n", tmpb->nb);
		tmpb = (tmpb->root ? tmpb : tmpb->previous);
	}
}