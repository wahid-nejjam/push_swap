/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:47:41 by conoel            #+#    #+#             */
/*   Updated: 2019/02/01 05:43:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**GETNEXTLINE perso qui renvoie len(line)+1
**et qui definit la fin de ligne par un caractere choisi
*/

static char	*ft_strchrend(char *str, char **line, int c)
{
	char			*end;
	size_t			index;

	index = 0;
	while (str[index] != c && str[index])
		index++;
	if (!(end = (char *)malloc(sizeof(char) * index + 1)))
		return (NULL);
	index = 0;
	while (str[index] != c && str[index] != '\0')
	{
		end[index] = str[index];
		index++;
	}
	end[index] = '\0';
	index = str[index] == c ? index + 1 : index;
	*line = end;
	return (str + index);
}

static t_list	*get_right_list(t_list **list, int fd)
{
	t_list	*new;

	new = *list;
	while (new)
	{
		if (new->content_size == (size_t)fd)
			return (new);
		new = new->next;
	}
	if (!(new = ft_lstnew("\0", 0)))
		return (NULL);
	new->content_size = (size_t)fd;
	ft_lstadd(list, new);
	new = *list;
	return (new);
}

long	get_next_line(int fd, char **line, int c)
{
	static t_list	*list;
	t_list			*list1;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			ret;

	if ((fd < 0 || read(fd, buffer, 0) < 0) || !(list1 =
			get_right_list(&list, fd)))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		tmp = list1->content;
		if (!(list1->content = buffer[0] != '\0' ?
				ft_strjoin(list1->content, buffer) : list1->content))
			return (-1);
		free(tmp);
		if (ft_strchr(buffer, c))
			break ;
	}
	ret = (ssize_t)ft_strlen(list1->content) ? 1 : 0;
	if (!(ft_memmove(list1->content, ft_strchrend((char *)
			list1->content, line, c), ft_strlen(list1->content) + 1)))
		return (-1);
	return (ret ? (long)ft_strlen(*line) + 1 : 0);
}
