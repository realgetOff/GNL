/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 03:26:09 by mforest-          #+#    #+#             */
/*   Updated: 2024/11/05 01:48:46 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_list
{
	char			*element;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
t_list				*get_last(t_list *tmp);
void				ft_read(int fd, t_list **tmp);
int					ft_nl(t_list *tmp);
void				add_to_tmp(t_list **tmp, char *stock, int count);
void				extract_line(t_list *tmp, char **line);
void				gen_line(char **line, t_list *tmp);
void				clean(t_list **tmp);
size_t				ft_strlen(const char *str);
void				free_tmp(t_list *tmp);

#endif
