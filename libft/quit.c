/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 10:47:52 by conoel            #+#    #+#             */
/*   Updated: 2019/02/01 05:28:34 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_free(char *msg, char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format++)
		free(va_arg(ap, void *));
	write(2, msg, ft_strlen(msg));
	exit(-1);
}

void	exit_(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(-1);
}
