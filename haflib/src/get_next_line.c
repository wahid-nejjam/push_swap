/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:47:41 by conoel            #+#    #+#             */
/*   Updated: 2019/04/12 17:48:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strchrend(char *str, char **line, int c)
{
	char			*end;
	size_t			index;

	index = 0;
	while (str[index] != c && str[index])
		index++;
	if (!(end = malloc_garbage(sizeof(char) * ((index) + 1))))
		return (NULL);
	index = 0;
	while (str[index] != c && str[index])
	{
		end[index] = str[index];
		index++;
	}
	end[index] = '\0';
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
	((char *)(new->content))[0] = '\0';
	new->content_size = (size_t)fd;
	ft_lstadd(list, new);
	new = *list;
	return (new);
}

size_t			get_next_line(int fd, char **line, int c)
{
	static t_list	*list;
	t_list			*list1;
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			ret;

	list1 = get_right_list(&list, fd);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		tmp = list1->content;
		if (!(list1->content = buffer[0] != '\0' ?
				ft_strjoin(list1->content, buffer) : list1->content))
			return (-1);
		if (ft_strchr(buffer, c))
			break ;
	}
	ret = (ssize_t)ft_strlen(list1->content) ? 1 : 0;
	if (!(ft_memmove(list1->content, ft_strchrend((char *)
			list1->content, line, c) + 1, ft_strlen(list1->content))))
		return (-1);
	return (ret ? ft_strlen(*line) + 1 : 0);
}
