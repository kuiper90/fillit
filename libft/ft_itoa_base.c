/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 04:38:06 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 04:48:42 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int value, int base)
{
	int count;

	count = 0;
	while (value != 0)
	{
		value /= base;
		count++;
	}
	return (count);
}

static char	conv(int rest)
{
	if (rest < 0)
		rest = -rest;
	if (rest >= 0 && rest <= 9)
		return (rest + '0');
	else
		return (rest + 55);
}

static char	*set_zero(char *buffer)
{
	buffer[0] = '0';
	buffer[1] = '\0';
	return (buffer);
}

char		*ft_itoa_base(int value, int base)
{
	int		i;
	int		temp;
	char	*buffer;

	i = 0;
	temp = 0;
	buffer = (char*)malloc(count(value, base) * sizeof(char) + 1);
	if (value == 0)
		return (set_zero(buffer));
	else if (value < 0 && base == 10)
	{
		buffer[0] = '-';
		temp = 1;
	}
	i = count(value, base) - 1 + temp;
	buffer[i + 1] = '\0';
	while (i >= temp)
	{
		buffer[i] = conv(value % base);
		value /= base;
		i--;
	}
	return (buffer);
}
