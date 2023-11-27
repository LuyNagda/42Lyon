/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:27:53 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/27 17:47:14 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **h1)
{
	int	temp;

	temp = (*h1)->content;
	(*h1)->content = (*h1)->next->content;
	(*h1)->next->content = temp;
}

void	push(t_list **h1, t_list **h2)
{
	t_list	*temp;

	temp = (*h2);
	(*h2) = (*h2)->next;
	if (!(*h1))
	{
		temp->next = NULL;
		*h1 = temp;
	}
	else
	{
		temp->next = (*h1);
		(*h1) = temp;
	}
}

void	rotate(t_list **head)
{
	t_list	*temp;
	t_list	*temp_head;

	temp = (*head);
	(*head) = (*head)->next;
	temp_head = ft_lstlast(head);
	temp_head->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_list **head)
{
	t_list	*temp;
	t_list	*temp_head;

	temp_head = (*head);
	while (temp_head->next->next)
		temp_head = temp_head->next;
	temp = temp_head->next;
	temp_head->next = NULL;
	temp->next = (*head);
	(*head) = temp;
}
