/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:27:53 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/20 14:04:15 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *h1, t_list *h2)
{
	t_list	*temp;

	temp = h2->next;
	h2->next = h1;
	h1->next = temp;
	return (h2);
}
void	push(t_list **h1, t_list **h2)
{
	int	temp;

	temp = (*h1)->content;
	(*h1)->content = (*h2)->content;
	(*h2)->content = temp;
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
	temp->next = head;
	(*head) = temp;
}