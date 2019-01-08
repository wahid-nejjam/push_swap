/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:13:24 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 17:55:15 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_elem	*new(int nb, t_elem *next, t_elem *previous, char root)
{
	t_elem	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->nb = nb;
	new->next = next;
	new->previous = previous;
	new->root = root;
	if (root)
	{
		new->previous = new;
		new->next = next;
	}
	return (new);
}