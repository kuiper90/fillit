/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 03:02:54 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:14:04 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *to, const void *from, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = -1;
	src = (unsigned char *)from;
	dest = (unsigned char *)to;
	if (n == 0 || src == dest)
		return (NULL);
	while (++i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			return ((void *)(dest + i + 1));
	}
	return (NULL);
}
