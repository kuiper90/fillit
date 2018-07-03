/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 03:06:31 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 03:08:32 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			rez[i] = f(i, s[i]);
			i++;
		}
	rez[i] = '\0';
	return (rez);
}
