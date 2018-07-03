/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 06:04:14 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/21 12:36:16 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *source;
	unsigned char *destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	if (len == 0 || src == dest)
		return (dest);
	else if (src > dest)
		return (ft_memcpy(dest, src, len));
	else
	{
		while (len--)
			destination[len] = source[len];
		return (dest);
	}
}
