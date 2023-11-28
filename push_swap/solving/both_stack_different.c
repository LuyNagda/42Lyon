/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_stack_different.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:47:28 by luynagda          #+#    #+#             */
/*   Updated: 2023/11/28 19:49:52 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	both_stack_different_1(t_list **stack_a, t_list **stack_b,
		int r_distance, int distance_b)
{
	while (r_distance)
	{
		rra(stack_a);
		r_distance--;
	}
	while (distance_b)
	{
		rb(stack_b);
		distance_b--;
	}
	pb(stack_a, stack_b);
}

void	both_stack_different_2(t_list **stack_a, t_list **stack_b,
		int distance, int r_distance_b)
{
	while (distance)
	{
		ra(stack_a);
		distance--;
	}
	while (r_distance_b)
	{
		rrb(stack_b);
		r_distance_b--;
	}
	pb(stack_a, stack_b);
}
