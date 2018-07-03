/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 04:30:22 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:12:24 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int nbr)
{
	int s;

	s = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		s++;
	}
	return (s);
}

char		*ft_itoa(int nbr)
{
	char	*buffer;
	int		i;
	int		sign;
	int		power;

	i = 0;
	sign = 1;
	power = ft_power(count_digits(nbr));
	buffer = ft_strnew(count_digits(nbr) + 1);
	if (!buffer)
		return (NULL);
	if (nbr < 0)
	{
		buffer[0] = '-';
		sign = -1;
		i = 1;
	}
	while (power != 0)
	{
		buffer[i++] = (nbr / power % 10) * sign + '0';
		power /= 10;
	}
	buffer[i] = '\0';
	return (buffer);
}
