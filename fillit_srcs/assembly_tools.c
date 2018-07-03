/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembly_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:37:34 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:30:33 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_tetrimino(t_list *tetrimino, int min_line, int min_col)
{
	t_list	*tetri_node;
	t_point	*point;

	tetri_node = tetrimino;
	while (tetri_node)
	{
		point = (t_point *)(tetri_node->content);
		point->l = point->l - min_line;
		point->c = point->c - min_col;
		tetri_node = tetri_node->next;
	}
}

int		get_min_col(t_list *tetrimino_list)
{
	t_list	*tetri_node;
	int		min;

	tetri_node = ((t_tetri *)(tetrimino_list->content))->one_piece;
	min = 10;
	while (tetri_node)
	{
		if (((t_point *)tetri_node->content)->c < min)
			min = ((t_point *)tetri_node->content)->c;
		tetri_node = tetri_node->next;
	}
	return (min);
}

int		get_min_line(t_list *tetrimino_list)
{
	t_list	*tetri_node;
	int		min;

	tetri_node = ((t_tetri *)(tetrimino_list->content))->one_piece;
	min = 10;
	while (tetri_node)
	{
		if (((t_point *)tetri_node->content)->l < min)
			min = ((t_point *)tetri_node->content)->l;
		tetri_node = tetri_node->next;
	}
	return (min);
}
