/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:36:12 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 03:04:43 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlen_next_word(char const *str, char c)
{
	int i;

	i = 0;
	while (!(str[i] == c) && str[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		word_count;
	char	**buffer;

	i = 0;
	if (s == NULL)
		return (NULL);
	word_count = ft_word_count((char *)s, c);
	buffer = (char **)malloc((word_count + 1) * sizeof(char *));
	if (buffer == NULL)
		return (NULL);
	while (s[0] == c)
		s++;
	while (i < word_count)
	{
		buffer[i] = ft_strsub(s, 0, strlen_next_word(s, c));
		if (buffer[i] == 0)
			return (0);
		s = s + strlen_next_word(s, c);
		while (s[0] == c)
			s++;
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
