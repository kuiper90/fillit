/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 21:58:19 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:39:38 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del(void *content, size_t size)
{
	if (size > 0)
		ft_memdel(content);
}

int		ft_lstcompare(t_list *first_node, t_list *second_node)
{
	int		count;
	t_point	*first;
	t_point	*second;

	count = 0;
	if (first_node == NULL || second_node == NULL)
		return (count);
	first = first_node->content;
	second = second_node->content;
	if (first->l == second->l - 1 && first->c == second->c)
		count++;
	else if (first->l == second->l && first->c == second->c + 1)
		count++;
	else if (first->l == second->l + 1 && first->c == second->c)
		count++;
	else if (first->l == second->l && first->c == second->c - 1)
		count++;
	return (count);
}

int		last_line_checker(char *buffer, int bytes_read)
{
	if (buffer[bytes_read + 1] == '\0' &&
			buffer[bytes_read - 1] == '\n' &&
			(buffer[bytes_read - 2] == '.' ||
			buffer[bytes_read - 2] == '#'))
		return (1);
	return (0);
}

t_tetri	*list_tetrimino(t_list *tetri_list)
{
	t_tetri *tetri_node;

	tetri_node = (t_tetri *)malloc(sizeof(t_tetri));
	tetri_node->one_piece = tetri_list;
	return (tetri_node);
}
