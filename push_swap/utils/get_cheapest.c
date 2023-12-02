/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:12:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/02 22:44:39 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_biggest(int a, int b)
{
	if (a > b)
		return (a);
	else if (b > a)
		return (b);
	else
		return (a);
}

int	get_count(int distance, int distance_b,
		int r_distance, int r_distance_b)
{
	int	count;

	count = get_biggest(distance, distance_b);
	if (get_biggest(r_distance, r_distance_b) < count)
		count = get_biggest(r_distance, r_distance_b);
	if ((distance + r_distance_b) < count)
		count = distance + r_distance_b;
	if ((r_distance + distance_b) < count)
		count = r_distance + distance_b;
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
	if (head->content < get_min(stack_b, -1))
		distance_b = get_distance(stack_b, get_max(stack_b, -1));
	else
		distance_b = get_distance(stack_b, to_find(stack_b, head->content));
	r_distance = ft_lstsize(*stack_a) - distance;
	r_distance_b = ft_lstsize(*stack_b) - distance_b;
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
	cheapest = 1000;
	head = *stack_a;
	while (head)
	{
		count = get_cheapest_count(stack_a, stack_b, head, count);
		if (count < cheapest)
		{
			cheapest = count;
			return_val = head->content;
		}
		head = head->next;
	}
	return (return_val);
}
