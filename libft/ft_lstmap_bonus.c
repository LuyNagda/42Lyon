/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:42:52 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/08 14:58:41 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_list;

	if (!del)
		return (0);
	head = lst;
	new_list = ft_lstnew(f(head->content));
	head = head->next;
	while (head)
	{
		ft_lstadd_back(&new_list, f(head->content));
		head = head->next;
	}
	return (new_list);
}
