/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:22 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 17:55:30 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (check_for_errors(argc, argv) == -1
			|| check_for_duplicates(argc, argv) == -1)
			return (-1);
		stack_a = initialize_stack(argc, argv);
		stack_b = NULL;
		if (ft_lstsize(stack_a) == 3)
			solve_for_3(&stack_a);
		if (ft_lstsize(stack_a) == 4)
			solve_for_4(&stack_a, &stack_b);
		if (ft_lstsize(stack_a) == 5)
			solve_for_5(&stack_a, &stack_b);
		else
			solve(&stack_a, &stack_b);
	}
	//t_list *head = stack_a;
	//t_list *head2 = stack_b;
	//printf("STACK A STARTSSSSSSS==========================\n");
	//while (head)
	//{
	//	printf("%d\n", head->content);
	//	head = head->next;
	//}
	//printf("STACK A ENDSSSSSSS==========================\n");
	//printf("STACK B STARTSSSSSSS==========================\n");
	//while (head2)
	//{
	//	printf("%d\n", head2->content);
	//	head2 = head2->next;
	//}
	//printf("STACK B ENDSSSSSSS==========================\n");
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
