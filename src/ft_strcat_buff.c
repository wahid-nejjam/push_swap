/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:26:18 by conoel            #+#    #+#             */
/*   Updated: 2019/02/04 14:28:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_strcat_buff(char *arg, char *buff)
{
	if (arg == NULL)
			return ;
	while (*arg)
	{
			*(buff++) = *(arg++);
			if (ft_strlen(buff) >= BUFF)
			{
					write(1, buff, BUFF);
					ft_bzero(buff, BUFF + 1);
			}
	}
}