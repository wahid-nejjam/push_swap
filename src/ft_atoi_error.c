/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:40:39 by conoel            #+#    #+#             */
/*   Updated: 2019/02/08 22:50:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_atoi_error(const char *nptr)
{
	int total;
	int signe;

	total = 0;
	if (*nptr != '-' && !ft_isdigit(*nptr))
		exit_("Learn how to type dumbass !\n");
	signe = (*nptr == '-') ? -1 : 1;
	nptr = (*nptr == '-' || *nptr == '+') ? nptr + 1 : nptr;
	while (ft_isdigit(*nptr))
		total = total * 10 + *nptr++ - 48;
	return (total * signe);
}
