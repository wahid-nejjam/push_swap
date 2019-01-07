/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:56:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 17:31:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

int		main(int argc, char **argv)
{
	t_elem	*last_a;
	char	*line[3];

	last_a = load_a(argc, argv);
	if (last_a == NULL)
	{
		write(2, "THAT DOESNT WORKED NIGGA", 26);
		return (-1);
	}
	/*open(1, O_RDONLY);
	while (get_next_line_char(1, line,'\n'))
	{
		
	}*/
	return (0);
}