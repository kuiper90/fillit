/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adobrito <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:02:20 by adobrito          #+#    #+#             */
/*   Updated: 2017/12/21 19:06:11 by adobrito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	if (content_size != 0)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head_new_list;
	t_list	*iterator;
	t_list	*node;

	node = f(lst);
	head_new_list = ft_lstnew(node->content, node->content_size);
	if (!head_new_list)
		return (NULL);
	iterator = head_new_list;
	while (lst->next)
	{
		lst = lst->next;
		node = f(lst);
		iterator->next = ft_lstnew(node->content, node->content_size);
		if (iterator->next == NULL)
		{
			ft_lstdel(&head_new_list, &del);
			return (NULL);
		}
		iterator = iterator->next;
	}
	return (head_new_list);
}
