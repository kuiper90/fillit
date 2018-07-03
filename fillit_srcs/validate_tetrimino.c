/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetrimino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:09:40 by adobrito          #+#    #+#             */
/*   Updated: 2018/01/17 16:47:56 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_string(char *str)
{
	int i;
	int j;

	i = 0;
	while (i != 4)
	{
		j = 0;
		while (str[j] != '\n' && j < 5)
		{
			if (str[j] != '.' && str[j] != '#')
				return (0);
			j++;
		}
		if (j != 4)
			return (0);
		str = str + 5;
		i++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int		count_hash(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (!(*str == '\n' && *(str + 1) == '\n'))
	{
		if (*str == '#')
			count++;
		else if (*str != '.' && *str != '\n')
			return (0);
		str++;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int		check_links(t_list **point)
{
	t_list	*first;
	t_list	*second;
	int		count;

	count = 0;
	first = *point;
	while (first != NULL)
	{
		second = *point;
		while (second != NULL)
		{
			count = count + ft_lstcompare(first, second);
			second = second->next;
		}
		first = first->next;
	}
	if (count >= 6)
		return (1);
	return (0);
}

char	**conv_mat(char *str)
{
	int		i;
	int		j;
	char	**mat;

	i = 0;
	mat = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
		mat[i++] = (char *)malloc(sizeof(char) * 4);
	if (mat == NULL)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			if (*str != '\n')
				mat[i][j] = *str;
			str++;
			j++;
		}
		i++;
	}
	return (mat);
}

void	tetri_list(char **mat, t_list **list)
{
	int		i;
	int		j;
	t_list	*new_node;
	t_point	*point;

	i = 0;
	point = (t_point *)malloc(sizeof(t_point));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mat[i][j] == '#')
			{
				point->l = i;
				point->c = j;
				new_node = ft_lstnew(point, sizeof(t_point));
				ft_lstappend(list, new_node);
			}
			j++;
		}
		i++;
	}
}
