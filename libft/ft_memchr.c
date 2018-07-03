/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:04:01 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:14:51 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char *source;

	source = (unsigned char *)src;
	while (len > 0)
	{
		if (*source != (unsigned char)c)
			len--;
		else
			return (source);
		source++;
	}
	return (0);
}
