/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 14:18:52 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/22 15:06:59 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *list;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			list = *alst;
			while (list->next != NULL)
				list = list->next;
			list->next = new;
		}
	}
}
