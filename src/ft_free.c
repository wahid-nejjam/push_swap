/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:43:53 by conoel            #+#    #+#             */
/*   Updated: 2019/01/15 10:54:18 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(t_elem *root_a, t_elem *root_b)
{
	t_elem	*tmp;
	t_elem	*tmp1;

	tmp = root_a->next;
	tmp1 = tmp;
	while (tmp != root_a)
	{
		free(tmp);
		tmp = tmp1->next;
		tmp1 = tmp;
	}
	free(root_a);
	tmp = root_b->next;
	tmp1 = tmp;
	while (tmp != root_b)
	{
		free(tmp);
		tmp = tmp1->next;
		tmp1 = tmp;
	}
	free(root_b);
}
