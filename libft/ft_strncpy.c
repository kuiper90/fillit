/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 02:58:02 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:59:53 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t length)
{
	int initial_len;

	initial_len = length;
	while (*src != '\0' && length > 0)
	{
		*dest++ = *src++;
		length--;
	}
	while (length--)
		*dest++ = '\0';
	return (dest - initial_len);
}
