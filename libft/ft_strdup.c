/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:17:53 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/12 18:17:59 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char *str2;

	str2 = (char *)malloc((ft_strlen(str1) + 1) * sizeof(char));
	if (str2 == NULL)
		return (NULL);
	ft_strcpy(str2, str1);
	return (str2);
}
