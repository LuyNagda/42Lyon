/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_for_3_4_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:54:11 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/24 17:02:04 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (head->content == min && head->next->content != next_min)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (head->content == next_min && head->next->content == min)
		sa(stack_a);
	else if (head->next->content == min && head->next->next->content == next_min)
		ra(stack_a);
	else if (head->content == next_min && head->next->next->content == min)
		rra(stack_a);
	else
	{
		sa(stack_a);
		rra(stack_a);
	}
}

// int	solve_for_4(t_list **stack_a)
// {

// }

// int	solve_for_5(t_list **stack_a)
// {
	
// }