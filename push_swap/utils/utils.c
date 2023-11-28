/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:27:02 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 17:12:17 by lunagda          ###   ########.fr       */
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
