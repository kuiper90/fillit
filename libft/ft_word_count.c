/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:34:11 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 02:17:23 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char *str, char c)
{
	int i;
	int word_count;

	if (!*str)
		return (0);
	i = 0;
	if (str[0] == c)
		word_count = 0;
	else
		word_count = 1;
	while (str[i + 1] != '\0')
	{
		if ((str[i] == c) && !(str[i + 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}
