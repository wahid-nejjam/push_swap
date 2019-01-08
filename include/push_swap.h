/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:56 by conoel            #+#    #+#             */
/*   Updated: 2019/01/08 17:23:27 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_elem
{
	char			root;
	int				nb;
	struct s_elem	*next;
	struct s_elem	*previous;
}					t_elem;

//	operations
void		swap(t_elem *last_a);
void		double_swap(t_elem *last_a, t_elem *last_b);
void		rotate(t_elem **last);
void		double_rotate(t_elem **last_a, t_elem **last_b);
void		r_rotate(t_elem **last);
void		double_r_rotate(t_elem **last_a, t_elem **last_b);
void		push(t_elem **last_a, t_elem **last_b);

//	checker functions
t_elem		*load_a(int argc, char **argv);
void		print_stack(t_elem *last);

//	utils
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_bzero(char *s, size_t n);

#endif
