/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetrimino.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:11:07 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/16 18:19:59 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*mat_checker(char *str)
{
	t_list **list;

	list = (t_list **)malloc(sizeof(t_list *) * 4);
	*list = NULL;
	if (!check_string(str))
		return (NULL);
	if (!count_hash(str))
		return (NULL);
	tetri_list(conv_mat(str), list);
	if (!check_links(list))
		return (NULL);
	return (*list);
}

t_list	*file_checker(char *filename)
{
	int		fd;
	t_list	*tetrimino_list;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tetrimino_list = read_checker(fd);
	close(fd);
	return (tetrimino_list);
}

t_list	*read_checker(int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_strnew(545);
	bytes_read = read(fd, buffer, 600 * (sizeof(char)));
	if (bytes_read == 0)
		return (NULL);
	else if (bytes_read > 545 || (bytes_read + 1) % 21 != 0)
		return (NULL);
	else if (last_line_checker(buffer, bytes_read))
		return (tetrimino_builder(bytes_read, buffer));
	return (NULL);
}

void	link_tetrimino(t_list *tetri_list, t_list **tetrimino_list)
{
	t_tetri	*tetrimino;
	t_list	*new_node;

	tetrimino = list_tetrimino(tetri_list);
	new_node = ft_lstnew(tetrimino, sizeof(t_tetri));
	ft_lstappend(tetrimino_list, new_node);
}

t_list	*tetrimino_builder(int bytes_read, char *buffer)
{
	t_list	*tetri_list;
	t_list	*tetrimino_list;

	tetrimino_list = NULL;
	buffer[bytes_read] = '\n';
	while (bytes_read > 0)
	{
		tetri_list = mat_checker(buffer);
		if (tetri_list == NULL)
			return (NULL);
		link_tetrimino(tetri_list, &tetrimino_list);
		buffer += 21;
		bytes_read -= 21;
	}
	return (tetrimino_list);
}
