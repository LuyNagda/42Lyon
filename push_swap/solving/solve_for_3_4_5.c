/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_for_3_4_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:54:11 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/25 00:57:38 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve_for_3_part(t_list **stack_a, t_list *head, int min, int next_min)
{
	if (head->content == min && head->next->content != next_min)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (head->content == next_min && head->next->content == min)
		sa(stack_a);
	else if (head->next->content == min
		&& head->next->next->content == next_min)
		ra(stack_a);
	else if (head->content == next_min && head->next->next->content == min)
		rra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	solve_for_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	solve_for_3_part(stack_a, head, min, next_min);
}

void	solve_for_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	solve_for_3(stack_a);
	pa(stack_a, stack_b);
}

void	solve_for_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	solve_for_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
