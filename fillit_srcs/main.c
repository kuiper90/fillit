/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 17:04:07 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/14 22:50:03 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	t_list *tetrimino_list;

	if (argc != 2)
		print_man();
	tetrimino_list = file_checker(argv[1]);
	if (tetrimino_list == NULL)
		exit_error();
	tetrimino_assembly(tetrimino_list);
	print_solution(get_solution(tetrimino_list));
	return (0);
}
