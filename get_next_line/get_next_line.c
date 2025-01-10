/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:38:22 by mforest-          #+#    #+#             */
/*   Updated: 2024/11/30 21:25:55 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*tmp = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	ft_read(fd, &tmp);
	if (!tmp)
		return (NULL);
	extract_line(tmp, &line);
	clean(&tmp);
	if (!line || line[0] == '\0')
	{
		free_tmp(tmp);
		tmp = NULL;
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read(int fd, t_list **tmp)
{
	char	*buffer;
	int		count;

	if (fd < 0 || !tmp)
		return ;
	count = 1;
	while (!ft_nl(*tmp) && count > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		count = (int)read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return ;
		}
		buffer[count] = '\0';
		if (count > 0)
			add_to_tmp(tmp, buffer, count);
		free(buffer);
	}
}

void	add_to_tmp(t_list **tmp, char *buffer, int count)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->element = malloc((count + 1) * sizeof(char));
	if (!new_node->element)
		return ;
	i = 0;
	while (buffer[i] && i < count)
	{
		new_node->element[i] = buffer[i];
		i++;
	}
	new_node->element[i] = '\0';
	if (!*tmp)
	{
		*tmp = new_node;
		return ;
	}
	last = get_last(*tmp);
	last->next = new_node;
}

void	extract_line(t_list *tmp, char **line)
{
	int	i;
	int	j;

	if (!tmp || !line)
		return ;
	gen_line(line, tmp);
	if (!*line)
		return ;
	j = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->element[i])
		{
			(*line)[j++] = tmp->element[i++];
			if (tmp->element[i - 1] == '\n')
				break ;
		}
		tmp = tmp->next;
	}
	(*line)[j] = '\0';
}

void	clean(t_list **tmp)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (tmp == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = get_last(*tmp);
	i = 0;
	while (last->element[i] && last->element[i] != '\n')
		i++;
	if (last->element && last->element[i] == '\n')
		i++;
	clean_node->element = malloc(sizeof(char) * ((ft_strlen(last->element) - i)
				+ 1));
	if (clean_node->element == NULL)
		return ;
	j = 0;
	while (last->element[i])
		clean_node->element[j++] = last->element[i++];
	clean_node->element[j] = '\0';
	free_tmp(*tmp);
	*tmp = clean_node;
}
