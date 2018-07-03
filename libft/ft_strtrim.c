/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:35:57 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 22:36:24 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	int		k;

	if (s == NULL)
		return (NULL);
	k = 0;
	i = 0;
	while (SEP(s[i]))
		i++;
	j = ft_strlen(s);
	if (i == j)
		return (ft_strnew(0));
	while (SEP(s[j - 1]))
		j--;
	str = ft_strnew(j - i);
	if (str == NULL)
		return (NULL);
	while (i < j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
