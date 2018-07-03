/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 22:54:24 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/23 00:56:21 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_putchar(char ch)
{
	if (32 <= ch && ch <= 127)
		write(1, &ch, 1);
	else
		write(1, ".", 1);
}

static char	conv_int_char(char ch)
{
	if (ch >= 0 && ch <= 9)
		return (ch + '0');
	else
		return (ch + 87);
}

static void	print_hex(unsigned char ch)
{
	int		i;
	char	*vector;

	if (!(vector = ft_strnew(1)))
		return ;
	i = 1;
	while (ch != 0)
	{
		vector[i] = ch % 16;
		ch /= 16;
		i--;
	}
	vector[0] = conv_int_char(vector[0]);
	vector[1] = conv_int_char(vector[1]);
	ft_putchar(vector[0]);
	ft_putchar(vector[1]);
	ft_strdel(&vector);
}

static void	number_to_char(unsigned char *p, unsigned int size)
{
	unsigned int	i;
	int				count;

	i = 0;
	if (size % 2 == 0)
		count = (16 - size) * 2 + (16 - size) / 2;
	else
		count = (16 - size - 1) * 2 + (16 - size - 1) / 2 + 3;
	while (count != 0)
	{
		ft_putchar(' ');
		count--;
	}
	while (i < size)
	{
		print_putchar(p[i]);
		i++;
	}
}

void		ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*p;
	unsigned int	i;

	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		print_hex(p[i]);
		if (i % 2 != 0)
			ft_putchar(' ');
		if ((i + 1) % 16 == 0 || i == size - 1)
		{
			number_to_char(p + (i / 16 * 16), (i + 1) - i / 16 * 16);
			ft_putchar('\n');
		}
		i++;
	}
}
