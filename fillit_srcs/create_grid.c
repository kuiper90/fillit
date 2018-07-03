/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 08:34:02 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:40:56 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid	*create_grid(int size)
{
	int		i;
	int		j;
	t_grid	*new_grid;

	i = 0;
	new_grid = (t_grid *)malloc(sizeof(t_grid));
	if (!(new_grid->grid = (char **)malloc(size * sizeof(char *))))
		return (NULL);
	while (i < size)
	{
		j = 0;
		if (!(new_grid->grid[i] = ft_strnew((size_t)size)))
		{
			del_grid(&new_grid, i);
			return (NULL);
		}
		while (j < size)
		{
			new_grid->grid[i][j] = '.';
			j++;
		}
		i++;
	}
	new_grid->size = size;
	return (new_grid);
}

void	del_grid(t_grid **input_grid, int i)
{
	while (i)
	{
		ft_strdel(&((*input_grid)->grid[i - 1]));
		i--;
	}
	ft_memdel((void **)(&(*input_grid)->grid));
	ft_memdel((void **)input_grid);
}

t_grid	*copy_grid(t_grid *original_grid)
{
	int		i;
	int		j;
	t_grid	*copy_grid;

	copy_grid = create_grid(original_grid->size);
	i = 0;
	while (i < original_grid->size)
	{
		j = 0;
		while (j < original_grid->size)
		{
			copy_grid->grid[i][j] = original_grid->grid[i][j];
			j++;
		}
		i++;
	}
	return (copy_grid);
}

int		grid_size(t_list *tetrimino_list)
{
	int count;
	int nb;

	nb = 0;
	count = 2;
	if (!tetrimino_list)
		return (0);
	while (tetrimino_list)
	{
		nb++;
		tetrimino_list = tetrimino_list->next;
	}
	while (count * count < nb * 4)
		count++;
	return (count);
}
