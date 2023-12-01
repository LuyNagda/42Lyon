/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:12:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 17:21:57 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_count(int distance, int distance_b,
		int r_distance, int r_distance_b)
{
	int	count;

	count = 0;
	if ((distance < r_distance) && (distance_b < r_distance_b))
	{
		if (distance > distance_b)
			count += distance;
		else
			count += distance_b;
	}
	else if ((distance > r_distance) && (distance_b > r_distance_b))
	{
		if (r_distance > r_distance_b)
			count += r_distance;
		else
			count += r_distance_b;
	}
	else if ((distance > r_distance) && (distance_b < r_distance_b))
		count += r_distance + distance_b;
	else
		count += distance + r_distance_b;
	return (count);
}

int	get_cheapest_count(t_list **stack_a, t_list **stack_b,
			t_list *head, int count)
{
	int	distance;
	int	distance_b;
	int	r_distance;
	int	r_distance_b;

	distance = get_distance(stack_a, to_find(stack_a, head->content));
	distance_b = get_distance(stack_b, to_find(stack_b, head->content));
	r_distance = ft_lstsize(*stack_a) - distance;
	r_distance_b = ft_lstsize(*stack_b)
		- get_distance(stack_b, to_find(stack_b, head->content));
	count = get_count(distance, distance_b, r_distance, r_distance_b);
	return (count);
}

int	get_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		count;
	int		cheapest;
	int		return_val;
	t_list	*head;

	return_val = 0;
	cheapest = 0;
	head = *stack_a;
	while (head)
	{
		count = 0;
		count = get_cheapest_count(stack_a, stack_b, head, count);
		if (count < cheapest || cheapest == 0)
		{
			cheapest = count;
			return_val = head->content;
		}
		if (cheapest == 1)
			break ;
		head = head->next;
	}
	return (return_val);
}
