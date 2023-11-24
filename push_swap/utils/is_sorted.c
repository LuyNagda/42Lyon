/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:50:03 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/24 16:58:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list **head)
{
	t_list	*temp;

	temp = (*head);
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return (-1);
		temp = temp->next;
	}
	return (0);
}
