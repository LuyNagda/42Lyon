/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:12:24 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 18:00:55 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	biggest(int a, int b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	else
		return (a);	
}

int	get_count(int distance, int distance_b,
		int r_distance, int r_distance_b)
{
	int	count;
	
	count = biggest(distance, distance_b);
	if ((biggest(r_distance, r_distance_b) < count))
		count = biggest(r_distance, r_distance_b);
	if ((distance + r_distance_b) < count)
		count = (distance + r_distance_b);
	if ((r_distance + distance_b) < count)
		count = (r_distance + distance_b);
	return (count);
	//if ((distance < r_distance) && (distance_b < r_distance_b))
	//{
	//	if (distance > distance_b)
	//		count += distance + 1;
	//	else
	//		count += distance_b + 1;
	//}
	//else if ((distance > r_distance) && (distance_b > r_distance_b))
	//{
	//	if (r_distance > r_distance_b)
	//		count += r_distance + 1;
	//	else
	//		count += r_distance_b + 1;
	//}
	//else if ((distance + r_distance_b) > (distance_b + r_distance))
	//	count += r_distance + distance_b + 1;
	//else
	//	count += distance + r_distance_b + 1;
	//return (count);
}

int	get_cheapest_count(t_list **stack_a, t_list **stack_b,
			t_list *head, int count)
{
	int	distance;
	int	distance_b;
	int	r_distance;
	int	r_distance_b;

	distance = get_distance(stack_a, to_find(stack_a, head->content));
	distance_b = get_distance(stack_b, r_to_find(stack_b, head->content));
	r_distance = ft_lstsize(*stack_a) - distance;
	r_distance_b = ft_lstsize(*stack_b) - distance_b;
	count = get_count(distance, distance_b, r_distance, r_distance_b);
	//printf("num: %d\n", head->content);
	//printf("distance: %d\n", distance);
	//printf("r_distance: %d\n", r_distance);
	//printf("distance_b: %d\n", distance_b);
	//printf("r_distance_b: %d\n", r_distance_b);
	//printf("count: %d\n", count);
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
		count = get_cheapest_count(stack_a, stack_b, head, count);
		if (count < cheapest || (cheapest == 0 && count != 0))
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
