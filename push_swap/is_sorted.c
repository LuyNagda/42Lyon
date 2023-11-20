/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:03 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/20 15:56:42 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **head)
{
	t_list	*temp;
	t_list	*next;

	temp = (*head);
	while (temp)
	{
		next = temp->next;
		while (next)
		{
			if (temp->content > next->content)
				return (-1);
			next = next->next;
		}
		temp = temp->next;
	}
	return (0);
}
