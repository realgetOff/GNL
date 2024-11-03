/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:38:22 by mforest-          #+#    #+#             */
/*   Updated: 2024/11/03 06:40:42 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*tmp = NULL;
	char			*line;

	if (fd < 0 || buff_size <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	ft_read(fd, &tmp);
	if (!tmp)
		return (NULL);
	extract_line(tmp, &line);
	clean(&tmp);
	if (!line[0])
	{
		free_tmp(tmp);
		free(line);
		return (NULL);
	}
	return (line);
}

void	ft_read(int fd, t_list **tmp)
{
	char	*stock;
	int		count;

	count = 1;
	while (!ft_nl(*tmp) && count != 0)
	{
		stock = malloc((buff_size + 1) * sizeof(char));
		if (!stock)
			return ;
		count = (int)read(fd, stock, buff_size);
		if ((!*tmp && count == 0) || count == -1)
		{
			free(stock);
			return ;
		}
		stock[count] = '\0';
		add_to_tmp(tmp, stock, count);
		free(stock);
	}
}

void	add_to_tmp(t_list **tmp, char *stock, int count)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->element = malloc((count + 1) * sizeof(char));
	if (new_node->element == NULL)
		return ;
	i = 0;
	while (stock[i] && i < count)
	{
		new_node->element[i] = stock[i];
		++i;
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

	if (!tmp)
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
			if (tmp->element[i] == '\n')
			{
				(*line)[++j] = tmp->element[i];
				break ;
			}
			(*line)[++j] = tmp->element[++i];
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
	if (!tmp || !clean_node)
		return ;
	clean_node->next = NULL;
	last = get_last(*tmp);
	i = 0;
	while (last->element[i] && last->element[i] != '\n')
		++i;
	if (last->element && last->element[i] == '\n')
		++i;
	clean_node->element = malloc((ft_strlen(last->element - i) + 1) * sizeof(char));
	if (clean_node->element== NULL)
		return ;
	j = 0;
	while (last->element[i])
		clean_node->element[++j] = last->element[++i];
	clean_node->element[j] = '\0';
	free_tmp(*tmp);
	*tmp = clean_node;
}
