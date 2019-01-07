/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:56 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 17:40:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>

typedef struct		s_elem
{
	int		nb;
	t_elem	*next;
	t_elem	*previous;
}					t_elem;
//operations
void		sa(t_elem *last_a);
void		sb(t_elem *last_b);
void		ss(t_elem *last_a, t_elem *last_b);

//checker functions
t_elem		*load_a(int argc, char **argv);

int			ft_atoi(char *str);

#endif