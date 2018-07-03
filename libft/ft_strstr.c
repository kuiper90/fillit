/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:15:04 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 22:34:11 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;

	if (*s2 == '\0')
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	while (i <= (int)(s1_len - s2_len))
	{
		j = 0;
		while (j < s2_len && s1[i + j] == s2[j])
			j++;
		if (j == s2_len)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
