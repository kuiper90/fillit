/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 05:15:05 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 05:18:07 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*rez;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	rez = ft_strnew(len);
	if (!rez)
		return (NULL);
	i = 0;
	if (s != NULL && f != NULL)
		while (s[i] != '\0')
		{
			rez[i] = f(s[i]);
			i++;
		}
	rez[i] = '\0';
	return (rez);
}
