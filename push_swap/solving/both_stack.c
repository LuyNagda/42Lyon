/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:39:41 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/29 11:40:03 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	both_stack_rotate_if(t_list **stack_a, t_list **stack_b,
		int distance, int distance_b)
{
	distance = distance - distance_b;
	while (distance_b)
	{
		rr(stack_a, stack_b);
		distance_b--;
	}
	while (distance)
	{
		ra(stack_a);
		distance--;
	}
	pb(stack_a, stack_b);
}

void	both_stack_rotate_else(t_list **stack_a, t_list **stack_b,
		int distance, int distance_b)
{
	distance_b = distance_b - distance;
	while (distance)
	{
		rr(stack_a, stack_b);
		distance--;
	}
	while (distance_b)
	{
		rb(stack_b);
		distance_b--;
	}
	pb(stack_a, stack_b);
}

void	both_stack_rotate(t_list **stack_a, t_list **stack_b,
		int distance, int distance_b)
{
	if (distance > distance_b)
		both_stack_rotate_if(stack_a, stack_b, distance, distance_b);
	else
		both_stack_rotate_else(stack_a, stack_b, distance, distance_b);
}

void	both_stack_rev_rotate_else(t_list **stack_a, t_list **stack_b,
		int r_distance, int r_distance_b)
{
	r_distance_b = r_distance_b - r_distance;
	while (r_distance)
	{
		rrr(stack_a, stack_b);
		r_distance--;
	}
	while (r_distance_b)
	{
		rrb(stack_b);
		r_distance_b--;
	}
	pb(stack_a, stack_b);
}

void	both_stack_rev_rotate(t_list **stack_a, t_list **stack_b,
		int r_distance, int r_distance_b)
{
	if (r_distance > r_distance_b)
	{
		r_distance = r_distance - r_distance_b;
		while (r_distance_b)
		{
			rrr(stack_a, stack_b);
			r_distance_b--;
		}
		while (r_distance)
		{
			rra(stack_a);
			r_distance--;
		}
		pb(stack_a, stack_b);
	}
	else
		both_stack_rev_rotate_else(stack_a, stack_b, r_distance, r_distance_b);
}
