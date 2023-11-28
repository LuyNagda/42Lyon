/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:47:27 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 15:24:46 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve(t_list **stack_a, t_list **stack_b)
{
	int		cheapest;
	int		distance;
	int		distance_b;
	int		r_distance;
	int		r_distance_b;
	//t_list	*head;

	if (ft_lstsize(*stack_a) == 3)
		solve_for_3(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (ft_lstsize(*stack_b) == 0)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	//t_list	*head2 = *stack_b;
	//printf("stack b======================================================\n");
	//while (head2)
	//{
	//	printf("%d\n", head2->content);
	//	head2 = head2->next;
	//}
	//printf("stack b ends=================================================\n");
	//head = *stack_a;
	//printf("stack a======================================================\n");
	//while (head)
	//{
	//	printf("%d\n", head->content);
	//	head = head->next;
	//}
	//printf("stack a ends=================================================\n");
	//head = *stack_a;
	distance = 0;
	distance_b = 0;
	r_distance_b = 0;
	r_distance = 0;
	if ((*stack_b)->content == get_min(stack_b, -1))
		rb(stack_b);
	cheapest = get_cheapest(stack_a, stack_b);
	distance = get_distance(stack_a, cheapest);
	if (cheapest > get_max(stack_b, -1) || cheapest < get_min(stack_b, -1))
	{
		distance = get_distance(stack_a, cheapest);
		r_distance = ft_lstsize(*stack_a) - distance;
		//printf("1cheapest: %d\n", cheapest);
		//printf("1to_find: %d\n", to_find(stack_b, cheapest));
		//printf("1distance: %d\n", distance);
		//printf("1r_distance: %d\n", r_distance);
		if (distance < r_distance)
		{
			while (distance)
			{
				ra(stack_a);
				distance--;
			}
			pb(stack_a, stack_b);
		}
		else
		{
			while (r_distance)
			{
				rra(stack_a);
				r_distance--;
			}
			pb(stack_a, stack_b);
		}
	}
	else
	{
		distance = get_distance(stack_a, cheapest);
		r_distance = (ft_lstsize(*stack_a) - distance);
		distance_b = get_distance(stack_b, to_find(stack_b, cheapest));
		r_distance_b = (ft_lstsize(*stack_b) - distance_b);
		//printf("2cheapest: %d\n", cheapest);
		//printf("2to_find: %d\n", to_find(stack_b, cheapest));
		//printf("2distance: %d\n", distance);
		//printf("2r_distance: %d\n", r_distance);
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
		if (distance_b < r_distance_b)
		{
			while (distance_b)
			{
				rb(stack_b);
				distance_b--;
			}
			pb(stack_a, stack_b);
		}
		else
		{
			while (r_distance_b)
			{
				rrb(stack_b);
				r_distance_b--;
			}
			pb(stack_a, stack_b);
		}
	}
	solve(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
	{
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
