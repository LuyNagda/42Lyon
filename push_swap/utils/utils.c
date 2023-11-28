/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:27:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 15:25:35 by lunagda          ###   ########.fr       */
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

int	get_max(t_list **stack_a, int val)
{
	t_list	*head;
	int		max;

	head = *stack_a;
	max = head->content;
	while (head->next)
	{
		head = head->next;
		if ((head->content > max) && head->content != val)
			max = head->content;
	}
	return (max);
}

int	to_find(t_list **stack_b, int val)
{
	t_list	*head;
	int		tmp;

	tmp = val;
	while (tmp)
	{
		head = *stack_b;
		while (head)
		{
			if (head->content == tmp)
			{
				return (tmp);
			}
			head = head->next;
		}
		tmp--;
	}
	return (0);
}

int	r_to_find(t_list **stack_a, int val)
{
	t_list	*head;

	while (42)
	{
		head = *stack_a;
		if (get_max(stack_a, -1) < val)
			return (head->content);
		while (head)
		{
			if (head->content == val)
			{
				return (val);
			}
			head = head->next;
		}
		val++;
	}
	return (0);
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
	if (!head)
		return (0);
	return (distance);
}

int	get_cheapest(t_list **stack_a, t_list **stack_b)
{
	int		count;
	int		distance;
	int		r_distance;
	int		cheapest;
	int		return_val;
	t_list	*head;

	return_val = 0;
	cheapest = 0;
	distance = 0;
	r_distance = 0;
	head = *stack_a;
	while (head)
	{
		count = 0;
		if (head->content > get_max(stack_b, -1) || head->content < get_min(stack_b, -1))
		{
			distance = get_distance(stack_a, get_max(stack_b, 1));
			r_distance = ft_lstsize(*stack_a) - distance;
			if (distance < r_distance)
				count += distance + 1;
			else
				count += r_distance + 1;
		}
		else
		{
			distance = get_distance(stack_b, to_find(stack_b, head->content))
					+ get_distance(stack_a, to_find(stack_a, head->content));
			r_distance = (get_distance(stack_b, to_find(stack_b, head->content))
					+ ft_lstsize(*stack_a)) - distance;
			if (distance < r_distance)
				count += distance + 1;
			else
				count += r_distance + 1;
		}
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
