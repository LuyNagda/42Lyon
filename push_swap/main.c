/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:22 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/24 17:01:41 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc > 1)
	{
		if (check_for_errors(argc, argv) == -1)
			return (-1);
		stack_a = initialize_stack(argv);
		if (argc == 4)
			solve_for_3(&stack_a);
		// if (argc == 5)
		// 	return (solve_for_4(stack_a));
		// if (argc == 6)
		// 	return (sovle_for_5(stack_a));
		// else
		// 	return (solve(stack_a));
	}
	return (0);
}
