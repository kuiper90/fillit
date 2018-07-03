/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 01:18:56 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:41:39 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_man(void)
{
	ft_putstr("Usage: ./fillit target_file\n");
	exit(0);
}

void	exit_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	print_solution(t_grid *original_grid)
{
	int i;

	i = 0;
	while (i < original_grid->size)
	{
		ft_putstr(original_grid->grid[i]);
		ft_putchar('\n');
		i++;
	}
}
