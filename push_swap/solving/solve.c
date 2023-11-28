/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:47:27 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 17:25:09 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//void	solve_part_1(t_list **stack_a, t_list **stack_b)
//{

//}

void	solve(t_list **stack_a, t_list **stack_b)
{
	int		cheapest;
	int		distance;
	int		distance_b;
	int		r_distance;
	int		r_distance_b;

	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_b) == 0)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	while (ft_lstsize(*stack_a) != 3)
	{
		cheapest = get_cheapest(stack_a, stack_b);
		distance = get_distance(stack_a, cheapest);
		r_distance = ft_lstsize(*stack_a) - distance;
		distance_b = get_distance(stack_b, to_find(stack_b, cheapest));
		r_distance_b = ft_lstsize(*stack_b) - distance_b;
		if (cheapest < get_min(stack_b, -1))
		{
			distance_b = get_distance(stack_b,
					r_to_find(stack_b, cheapest)) + 1;
			r_distance_b = ft_lstsize(*stack_b) - distance_b;
		}
		if ((distance < r_distance) && (distance_b < r_distance_b))
		{
			if (distance > distance_b)
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
			else
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
		}
		else if ((distance > r_distance) && (distance_b > r_distance_b))
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
		}
		else if ((distance > r_distance) && (distance_b < r_distance_b))
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
		else
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
	}
	solve_for_3(stack_a);
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
