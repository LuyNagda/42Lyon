/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_after_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:05:58 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 17:46:36 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_after_push(t_list **stack_a)
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
