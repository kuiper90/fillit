/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:40:06 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:32:20 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int size;

	size = ft_strlen(str) + 1;
	while (size--)
		if (*(str + size) == (char)c)
			return ((char *)(str + size));
	return (NULL);
}
