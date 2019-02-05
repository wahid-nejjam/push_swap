/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:54:56 by conoel            #+#    #+#             */
/*   Updated: 2019/02/05 17:03:33 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"

# define SEC 1000000
# define BUFF 2048

typedef struct		s_elem
{
	char			root;
	int				nb;
	struct s_elem	*next;
	struct s_elem	*previous;
}					t_elem;

typedef struct		s_ft
{
	char			ft[5];
	int				index;
	struct s_ft		*next;
}					t_ft;

//	operations
void		swap(t_elem *last_a);
void		double_swap(t_elem *last_a, t_elem *last_b);
void		rotate(t_elem *last);
void		double_rotate(t_elem *last_a, t_elem *last_b);
void		r_rotate(t_elem *last);
void		double_r_rotate(t_elem *last_a, t_elem *last_b);
void		push(t_elem *last_a, t_elem *last_b);

//	specific functions
t_elem		*load_a(int argc, char **argv);
void		print_stack(t_elem *root_a, t_elem *root_b, char *ft, t_elem *mark);
void		ft_free(t_elem *root_a, t_elem *root_b);
t_elem		*new(int nb, t_elem *next, t_elem *previous, char root);
int			issort(t_elem *root_a);
int			isrsort(t_elem *root_a);
t_elem		*ft_get_min(t_elem *root_a);
t_elem		*ft_get_max(t_elem *root_a);
int			ft_get_index(t_elem *elem);
void		exec_ft(char *ft, t_elem *root_a, t_elem *root_b, int delay);
t_elem		*ft_geti_max(t_elem *root, int index);
t_elem		*ft_geti_min(t_elem *root, int index);
t_elem		*get_at_index(t_elem *root, int index);
int			heat_size(t_elem *root);
t_elem		*get_median(t_elem *root);

//printstack
void	print_sb(t_elem *b);
void	print_rb(t_elem *b);
void	print_rrb(t_elem *b);
void	print_sa(t_elem *a, t_elem *mark);
void	print_rra(t_elem *a, t_elem *mark);
void	print_ra(t_elem *a, t_elem *mark);
void    ft_strcat_buff(char *arg, char *buff);

#endif
