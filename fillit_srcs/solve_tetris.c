/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:18:33 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 23:18:06 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_place(t_grid **input_grid, t_list *piece_list, int i, int j)
{
	t_list *node;

	node = ((t_tetri *)(piece_list->content))->one_piece;
	while (node)
	{
		if ((i + ((t_point *)(node->content))->l >= (*input_grid)->size) ||
			(j + ((t_point *)(node->content))->c >= (*input_grid)->size) ||
			((*input_grid)->grid[i + ((t_point *)(node->content))->l][j
			+ ((t_point *)(node->content))->c] != '.'))
			return (0);
		node = node->next;
	}
	return (1);
}

int		put_piece(t_grid **input_grid, t_list *piece_list, int i, int j)
{
	t_list *node;

	if (try_place(input_grid, piece_list, i, j))
	{
		node = ((t_tetri *)(piece_list->content))->one_piece;
		while (node)
		{
			(*input_grid)->grid[i + ((t_point *)(node->content))->l][j +
				((t_point *)(node->content))->c] =
				((t_tetri *)(piece_list->content))->letter;
			node = node->next;
		}
		return (1);
	}
	return (0);
}

void	del_piece(t_grid **input_grid, t_list *piece_list, int i, int j)
{
	t_list *node;

	node = ((t_tetri *)(piece_list->content))->one_piece;
	while (node)
	{
		(*input_grid)->grid[i + ((t_point *)(node->content))->l][j
			+ ((t_point *)(node->content))->c] = '.';
		node = node->next;
	}
}

int		fill_tetri(t_list *tetrimino, t_grid **input_grid)
{
	int i;
	int j;

	if (!tetrimino)
		return (1);
	i = -1;
	while (++i < (*input_grid)->size)
	{
		j = -1;
		while (++j < (*input_grid)->size)
		{
			if (put_piece(input_grid, tetrimino, i, j))
			{
				if (fill_tetri(tetrimino->next, input_grid))
					return (1);
				else
					del_piece(input_grid, tetrimino, i, j);
			}
		}
	}
	return (0);
}

t_grid	*get_solution(t_list *tetrimino)
{
	int		size;
	t_grid	*input_grid;

	size = grid_size(tetrimino);
	if (!(input_grid = create_grid(size)))
		return (NULL);
	while (!fill_tetri(tetrimino, &input_grid))
	{
		del_grid(&input_grid, size);
		size++;
		if (!(input_grid = create_grid(size)))
			return (NULL);
	}
	return (input_grid);
}
