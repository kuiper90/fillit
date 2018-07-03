/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 22:46:17 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 22:47:08 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char ch, char *charset)
{
	int i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

int			ft_word_counts(char *str, char *charset)
{
	int	i;
	int	word_count;

	if (!*str)
		return (0);
	i = 0;
	if (is_separator(str[0], charset))
		word_count = 0;
	else
		word_count = 1;
	while (str[i + 1] != '\0')
	{
		if (is_separator(str[i], charset) &&
				!is_separator(str[i + 1], charset))
			word_count++;
		i++;
	}
	return (word_count);
}
