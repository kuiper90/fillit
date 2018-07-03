/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:27:36 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:29:31 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t count;

	count = 0;
	while (dest[count] != '\0' && count < size)
		count++;
	if (!*src || !src)
		return (count);
	if (!size || count == size)
		return (count + ft_strlen(src));
	i = count;
	while (i < size - 1 && src[i - count] != '\0')
	{
		dest[i] = src[i - count];
		i++;
	}
	dest[i] = '\0';
	return (count + ft_strlen(src));
}
