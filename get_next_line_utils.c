/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:39:12 by mforest-          #+#    #+#             */
/*   Updated: 2024/11/03 06:45:09 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_nl(t_list *tmp)
{
	int		i;
	t_list	*current;

	if (!tmp)
		return (0);
	current = tmp;
	while (current)
	{
		i = 0;
		while (current->element[i])
		{
			if (current->element[i] == '\n')
				return (1);
			i++;
		}
		current = current->next;
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
	int	newline_found;

	len = 0;
	newline_found = 0;
	i = 0;
	while (tmp)
	{
		while (tmp->element[i])
		{
			if (tmp->element[i] == '\n')
			{
				len++;
				newline_found = 1;
				break ;
			}
			len++;
			i++;
		}
		if (newline_found)
			break ;
		tmp = tmp->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line)
	{
		len = 0;
		while (tmp)
		{
			i = 0;
			while (tmp->element[i])
			{
				(*line)[len++] = tmp->element[i];
				if (tmp->element[i] == '\n')
				{
					(*line)[len] = '\0';
					return ;
				}
				i++;
			}
			tmp = tmp->next;
		}
		(*line)[len] = '\0';
	}
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
