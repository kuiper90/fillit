/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assemble_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:06:50 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:31:38 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetrimino_assembly(t_list *tetrimino_list)
{
	tetri_letter(&tetrimino_list);
	normalize_tetrimino(&tetrimino_list);
}

t_list	**tetri_letter(t_list **list)
{
	char	letter;
	t_list	*tetris;

	letter = 'A';
	tetris = *list;
	while (tetris)
	{
		((t_tetri *)(tetris->content))->letter = letter;
		letter++;
		tetris = tetris->next;
	}
	return (list);
}

void	normalize_tetrimino(t_list **tetrimino_list)
{
	t_list	*tetrimino;
	t_list	*tetrimino_node;
	int		min_col;
	int		min_line;

	tetrimino_node = *tetrimino_list;
	while (tetrimino_node)
	{
		min_col = get_min_col(tetrimino_node);
		min_line = get_min_line(tetrimino_node);
		tetrimino = ((t_tetri *)(tetrimino_node->content))->one_piece;
		move_tetrimino(tetrimino, min_line, min_col);
		tetrimino_node = tetrimino_node->next;
	}
}
