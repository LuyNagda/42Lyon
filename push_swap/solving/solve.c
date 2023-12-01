/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:47:27 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/01 16:02:34 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_b(t_list **stack_b)
{
	int	distance;
	int	r_distance;

	distance = get_distance(stack_b, get_max(stack_b, -1));
	r_distance = ft_lstsize(*stack_b) - distance;
	if (distance < r_distance)
	{
		while (distance)
		{
			rb(stack_b);
			distance--;
		}
	}
	else
	{
		while (r_distance)
		{
			rrb(stack_b);
			r_distance--;
		}
	}
}

void	sort_push_in_a(t_list **stack_a, t_list **stack_b,
		int distance, int r_distance)
{
	while (ft_lstsize(*stack_b))
	{
		distance = get_distance(stack_a,
				r_to_find(stack_a, (*stack_b)->content));
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
	while (!is_sorted(stack_a))
		rra(stack_a);
}

void	solve_while_loop(t_list **stack_a, t_list **stack_b)
{
	int		distance;
	int		distance_b;
	int		r_distance;
	int		r_distance_b;

	distance = get_distance(stack_a, get_cheapest(stack_a, stack_b));
	r_distance = ft_lstsize(*stack_a) - distance;
	distance_b = get_distance(stack_b,
			to_find(stack_b, get_cheapest(stack_a, stack_b)));
	r_distance_b = ft_lstsize(*stack_b) - distance_b;
	if (get_cheapest(stack_a, stack_b) < get_min(stack_b, -1))
	{
		distance_b = get_distance(stack_b,
				r_to_find(stack_b, get_cheapest(stack_a, stack_b))) + 1;
		r_distance_b = ft_lstsize(*stack_b) - distance_b;
	}
	if ((distance < r_distance) && (distance_b < r_distance_b))
		both_stack_rotate(stack_a, stack_b, distance, distance_b);
	else if ((distance > r_distance) && (distance_b > r_distance_b))
		both_stack_rev_rotate(stack_a, stack_b, r_distance, r_distance_b);
	else if ((distance > r_distance) && (distance_b < r_distance_b))
		both_stack_different_1(stack_a, stack_b, r_distance, distance_b);
	else
		both_stack_different_2(stack_a, stack_b, distance, r_distance_b);
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
	solve_for_3(stack_a);
	sort_push_in_a(stack_a, stack_b, distance, r_distance);
}
