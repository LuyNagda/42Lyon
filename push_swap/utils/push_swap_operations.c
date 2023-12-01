/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:14:32 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/24 16:56:44 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return (-1);
	swap(stack_a);
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return (-1);
	swap(stack_b);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 1)
		return (-1);
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 1)
		return (-1);
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
	return (0);
}
