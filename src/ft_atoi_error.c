/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:40:39 by conoel            #+#    #+#             */
/*   Updated: 2019/02/11 17:26:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_if_number(const char *nptr)
{
	if (*nptr != '-' && !ft_isdigit(*nptr))
		exit_(NULL);
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			exit_(NULL);
		nptr++;
	}
}

int			ft_atoi_error(const char *nptr)
{
	long	total;
	int		signe;

	total = 0;
	check_if_number(nptr);
	signe = (*nptr == '-') ? -1 : 1;
	nptr = (*nptr == '-' || *nptr == '+') ? nptr + 1 : nptr;
	while (ft_isdigit(*nptr))
	{
		total = total * 10 + *nptr++ - 48;
		if ((total > 2147483648 && signe == -1) ||
			(total > 2147483647 && signe == 1))
			exit_(NULL);
	}
	return (total * signe);
}
