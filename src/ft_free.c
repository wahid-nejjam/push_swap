/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:43:53 by conoel            #+#    #+#             */
/*   Updated: 2019/02/04 20:06:41 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_list(t_elem *root)
{
	t_elem	*tmp;
	t_elem	*tmp1;

	if (!root)
		return ;
	tmp = root->next;
	tmp1 = tmp;
	while (tmp != root)
	{
		free(tmp);
		tmp = tmp1->next;
		tmp1 = tmp;
	}
	free(root);
}

void	ft_free(t_elem *root_a, t_elem *root_b)
{
	free_list(root_a);
	free_list(root_b);
}
