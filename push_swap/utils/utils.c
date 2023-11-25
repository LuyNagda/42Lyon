/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:27:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/25 00:54:21 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min(t_list **stack_a, int val)
{
	t_list	*head;
	int		min;

	head = *stack_a;
	min = head->content;
	while (head->next)
	{
		head = head->next;
		if ((head->content < min) && head->content != val)
			min = head->content;
	}
	return (min);
}

int	get_distance(t_list **stack_a, int content)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack_a;
	while (head)
	{
		if (head->content == content)
			break ;
		head = head->next;
		distance++;
	}
	return (distance);
}
