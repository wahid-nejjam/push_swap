/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:43:53 by conoel            #+#    #+#             */
/*   Updated: 2019/02/11 17:59:50 by conoel           ###   ########.fr       */
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
	while (tmp != root)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	free(root);
}

void		ft_free(t_elem *root_a, t_elem *root_b)
{
	if (root_a)
		free_list(root_a);
	if (root_b)
		free_list(root_b);
}
