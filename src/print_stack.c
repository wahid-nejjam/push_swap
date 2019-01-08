/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 12:59:12 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 18:50:50 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		print_stack(t_elem *root)
{
	t_elem	*tmp;

	tmp = root->previous;
	write(1, "Liste_a\n", 9);
	while (!tmp->root)
	{
		printf("|%d|\n", tmp->nb);
		tmp = tmp->previous;
	}
	write(1, "\n", 1);
}