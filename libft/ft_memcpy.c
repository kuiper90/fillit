/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 05:20:45 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/20 05:34:38 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;

	i = 0;
	if (len == 0 || src == dest)
		return (dest);
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	while (i < len)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
