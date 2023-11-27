/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:47:27 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/27 20:25:13 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve(t_list **stack_a, t_list **stack_b)
{
	int		cheapest;
	int		distance;
	int		r_distance;
	t_list	*head;

	if (ft_lstsize(*stack_a) == 3)
		solve_for_3(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_b) == 0)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	head = *stack_a;
	distance = 0;
	r_distance = 0;
	cheapest = get_cheapest(stack_a, stack_b);
	distance = get_distance(stack_a, cheapest);
	if (head->content > get_max(stack_b, -1) || head->content < get_min(stack_b, -1))
	{
		if ((*stack_b)->content == get_max(stack_b, -1))
			pb(stack_a, stack_b);
		else
		{
			distance = get_distance(stack_a, get_max(stack_b, -1));
			r_distance = ft_lstsize(*stack_b) - distance;
			if (distance < r_distance)
			{
				while (distance)
				{
					rb(stack_b);
					distance--;
				}
				pb(stack_a, stack_b);
			}
			else
			{
				while (r_distance)
				{
					rrb(stack_b);
					r_distance--;
				}
				pb(stack_a, stack_b);
			}
		}
	}
	else
	{
		distance = get_distance(stack_b, to_find(stack_b, cheapest));
		r_distance = (ft_lstsize(*stack_b) - distance);
		if (distance < r_distance)
		{
			while (distance)
			{
				rb(stack_b);
				distance--;
			}
			pb(stack_a, stack_b);
			rrb(stack_b);
		}
		else
		{
			while (r_distance)
			{
				rrb(stack_b);
				r_distance--;
			}
			pb(stack_a, stack_b);
			rb(stack_b);
		}
	}
	solve(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
	{
		while ((ft_lstlast(stack_a)->content) > ((*stack_b)->content))
			rra(stack_a);
		while (ft_lstsize(*stack_b))
		{
			distance = get_distance(stack_a, r_to_find(stack_a, (*stack_b)->content));
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
	}
	while (!is_sorted(stack_a))
		rra(stack_a);
}
