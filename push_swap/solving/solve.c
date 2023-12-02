/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:47:27 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/02 22:32:21 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a(t_list **stack_a)
{
	int	distance;
	int	r_distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	r_distance = ft_lstsize(*stack_a) - distance;
	if (distance < r_distance)
	{
		while (distance)
		{
			ra(stack_a);
			distance--;
		}
	}
	else
	{
		while (r_distance)
		{
			rra(stack_a);
			r_distance--;
		}
	}
}

void	sort_push_in_a(t_list **stack_a, t_list **stack_b,
		int distance, int r_distance)
{
	distance = get_distance(stack_a, r_to_find(stack_a, (*stack_b)->content));
	if ((*stack_b)->content > get_max(stack_a, -1))
		distance = get_distance(stack_a,
				to_find(stack_a, (*stack_b)->content)) + 1;
	r_distance = ft_lstsize(*stack_a) - distance;
	if (distance < r_distance)
	{
		while (distance)
		{
			ra(stack_a);
			distance--;
		}
	}
	else
	{
		while (r_distance)
		{
			rra(stack_a);
			r_distance--;
		}
	}
	pa(stack_a, stack_b);
}

int	cheapest_operation(int distance, int distance_b,
	int r_distance, int r_distance_b)
{
	int	count;
	int	operation;

	count = get_biggest(distance, distance_b);
	operation = 1;
	if (get_biggest(r_distance, r_distance_b) < count)
	{
		count = get_biggest(r_distance, r_distance_b);
		operation = 2;
	}
	if ((distance + r_distance_b) < count)
	{
		count = distance + r_distance_b;
		operation = 3;
	}
	if ((r_distance + distance_b) < count)
	{
		count = r_distance + distance_b;
		operation = 4;
	}
	return (operation);
}

void	solve_while_loop(t_list **stack_a, t_list **stack_b)
{
	int	distance;
	int	distance_b;
	int	r_distance;
	int	r_distance_b;
	int	operation;

	distance = get_distance(stack_a, get_cheapest(stack_a, stack_b));
	r_distance = ft_lstsize(*stack_a) - distance;
	distance_b = get_distance(stack_b, 
			to_find(stack_b, get_cheapest(stack_a, stack_b)));
	if (get_cheapest(stack_a, stack_b) < get_min(stack_b, -1))
		distance_b = get_distance(stack_b, get_max(stack_b, -1));
	r_distance_b = ft_lstsize(*stack_b) - distance_b;
	operation = cheapest_operation(distance, distance_b,
			r_distance, r_distance_b);
	if (operation == 1)
		both_stack_rotate(stack_a, stack_b, distance, distance_b);
	else if (operation == 2)
		both_stack_rev_rotate(stack_a, stack_b, r_distance, r_distance_b);
	else if (operation == 3)
		both_stack_different_2(stack_a, stack_b, distance, r_distance_b);
	else
		both_stack_different_1(stack_a, stack_b, r_distance, distance_b);
}

void	solve(t_list **stack_a, t_list **stack_b)
{
	int		distance;
	int		r_distance;

	distance = 0;
	r_distance = 0;
	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_b) == 0)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_a) != 3 && !is_sorted(stack_a))
		solve_while_loop(stack_a, stack_b);
	if (!is_sorted(stack_a))
		solve_for_3(stack_a);
	while (ft_lstsize(*stack_b))
		sort_push_in_a(stack_a, stack_b, distance, r_distance);
	sort_a(stack_a);
}
