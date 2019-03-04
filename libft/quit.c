/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 10:47:52 by conoel            #+#    #+#             */
/*   Updated: 2019/03/04 12:10:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**static void	msg_(char *msg)
**{
**	if (msg == NULL)
**	{
**			write(2, "Memory allocation error :<\n", 27);
**	}
**	else
**	{
**		write(2, msg, ft_strlen(msg));
**	}
**	write(2, "\7", 1);
**}
*/

static void	msg_(char *msg)
{
	msg = NULL;
	write(2, "Error\n", 6);
	write(2, "\7", 1);
}

void		exit_free(char *msg, int format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (format-- > 0)
		free(va_arg(ap, void *));
	msg_(msg);
	exit(-1);
}

void		exit_(char *msg)
{
	msg_(msg);
	exit(-1);
}
