/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:22 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/02 16:02:58 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		if (check_for_errors(argc, argv) == -1
			|| check_for_duplicates(argc, argv) == -1)
			return (-1);
		stack_a = initialize_stack(argc, argv);
		stack_b = NULL;
		if (ft_lstsize(stack_a) == 3)
			solve_for_3(&stack_a);
		else if (ft_lstsize(stack_a) == 4)
			solve_for_4(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) == 5)
			solve_for_5(&stack_a, &stack_b);
		else if (ft_lstsize(stack_a) > 5)
			solve(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
	return (0);
}
