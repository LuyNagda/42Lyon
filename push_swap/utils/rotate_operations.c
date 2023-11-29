/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:23:48 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 18:18:29 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return (0);
	if (ft_lstsize(*stack_a) < 1)
		return (-1);
	rotate(stack_a);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return (0);
	if (ft_lstsize(*stack_b) < 1)
		return (-1);
	rotate(stack_b);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (0);
	if (ft_lstsize(*stack_a) < 1 || ft_lstsize(*stack_b) < 1)
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return (0);
}
