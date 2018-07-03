/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 03:53:51 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/20 03:54:32 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t nr)
{
	unsigned char *dest;

	dest = (unsigned char *)src;
	while (nr > 0)
	{
		*dest++ = '\0';
		nr--;
	}
}