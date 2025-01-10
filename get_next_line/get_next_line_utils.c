/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:39:12 by mforest-          #+#    #+#             */
/*   Updated: 2024/11/22 01:09:26 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_nl(t_list *tmp)
{
	int		i;
	t_list	*current;

	if (!tmp)
		return (0);
	current = get_last(tmp);
	i = 0;
	while (current->element[i])
	{
		if (current->element[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

t_list	*get_last(t_list *tmp)
{
	t_list	*current;

	current = tmp;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	gen_line(char **line, t_list *tmp)
{
	int	i;
	int	len;

	len = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->element[i])
		{
			if (tmp->element[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			++i;
		}
		tmp = tmp->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_tmp(t_list *tmp)
{
	t_list	*current;
	t_list	*next;

	current = tmp;
	while (current)
	{
		free(current->element);
		next = current->next;
		free(current);
		current = next;
	}
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}
