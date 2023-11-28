/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:22 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 17:21:01 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		if (check_for_errors(argc, argv) == -1)
			return (-1);
		stack_a = initialize_stack(argv);
		stack_b = NULL;
		if (argc == 4)
			solve_for_3(&stack_a);
		if (argc == 5)
			solve_for_4(&stack_a, &stack_b);
		if (argc == 6)
			solve_for_5(&stack_a, &stack_b);
		else
			solve(&stack_a, &stack_b);
	}
	//while (stack_a)
	//{
	//	fflush(stdout);
	//	printf("%d\n", stack_a->content);
	//	stack_a = stack_a->next;
	//}
	//printf("==================================\n");
	//while (stack_b)
	//{
	//	fflush(stdout);
	//	printf("%d\n", stack_b->content);
	//	stack_b = stack_b->next;
	//}
	return (0);
}
