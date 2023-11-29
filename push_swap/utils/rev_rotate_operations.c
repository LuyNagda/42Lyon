/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:28:01 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 18:18:22 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return (0);
	if (ft_lstsize(*stack_a) < 1)
		return (-1);
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return (0);
	if (ft_lstsize(*stack_b) < 1)
		return (-1);
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	if (ft_lstsize(*stack_a) < 1 || ft_lstsize(*stack_b) < 1)
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
