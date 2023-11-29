/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:47:27 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/29 18:17:07 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	cheapest_operation(int distance, int distance_b, int r_distance, int r_distance_b)
{
	int	count;
	int	store;
	
	count = biggest(distance, distance_b);
	store = 1;
	if ((biggest(r_distance, r_distance_b) < count))
	{
		count = biggest(r_distance, r_distance_b);
		store = 2;
	}
	if ((distance + r_distance_b) < count)
	{
		count = (distance + r_distance_b);
		store = 3;
	}
	if ((r_distance + distance_b) < count)
	{
		count = (r_distance + distance_b);
		store = 4;
	}
	return (store);
}

void	sort_push_in_a(t_list **stack_a, t_list **stack_b)
{
	int	distance;
	int	distance_b;
	int	r_distance;
	int	r_distance_b;
	int	store;
	
	distance_b = get_distance(stack_b, get_cheapest(stack_b, stack_a));
	r_distance_b = ft_lstsize(*stack_b) - distance_b;
	distance = get_distance(stack_a,
			r_to_find(stack_a, get_cheapest(stack_b, stack_a)));
	r_distance = ft_lstsize(*stack_a) - distance;
	if (get_cheapest(stack_b, stack_a) > get_max(stack_a, -1))
	{
		distance = get_distance(stack_a,
			to_find(stack_a, get_cheapest(stack_b, stack_a))) + 1;
		r_distance = ft_lstsize(*stack_a) - distance;
	}
	//printf("cheapest: %d\n", get_cheapest(stack_b, stack_a));
	//printf("distance: %d\n", distance);
	//printf("r_distance: %d\n", r_distance);
	//printf("distance_b: %d\n", distance_b);
	//printf("r_distance_b: %d\n", r_distance_b);
	store = cheapest_operation(distance, distance_b, r_distance, r_distance_b);
	if (get_cheapest(stack_b, stack_a) == 85)
		printf("store: %d\n", store);
	if (store == 1)
		both_stack_rotate_push_a(stack_a, stack_b, distance, distance_b);
	else if (store == 2)
		both_stack_rev_rotate_push_a(stack_a, stack_b, r_distance, r_distance_b);
	else if (store == 4)
		both_stack_different_1_push_a(stack_a, stack_b, r_distance, distance_b);
	else
		both_stack_different_2_push_a(stack_a, stack_b, distance, r_distance_b);
	//t_list *head = *stack_a;
	//t_list *head2 = *stack_b;
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
}

void	solve_while_loop(t_list **stack_a, t_list **stack_b)
{
	int	distance;
	int	distance_b;
	int	r_distance;
	int	r_distance_b;
	int	store;

	distance = get_distance(stack_a, get_cheapest(stack_a, stack_b));
	r_distance = ft_lstsize(*stack_a) - distance;
	distance_b = get_distance(stack_b,
			to_find(stack_b, get_cheapest(stack_a, stack_b)));
	r_distance_b = ft_lstsize(*stack_b) - distance_b;
	if (get_cheapest(stack_a, stack_b) < get_min(stack_b, -1))
	{
		distance_b = get_distance(stack_b,
				r_to_find(stack_b, get_cheapest(stack_a, stack_b))) + 1;
		r_distance_b = ft_lstsize(*stack_b) - distance_b;
	}
	store = cheapest_operation(distance, distance_b, r_distance, r_distance_b);
	if (store == 1)
		both_stack_rotate(stack_a, stack_b, distance, distance_b);
	else if (store == 2)
		both_stack_rev_rotate(stack_a, stack_b, r_distance, r_distance_b);
	else if (store == 4)
		both_stack_different_1(stack_a, stack_b, r_distance, distance_b);
	else
		both_stack_different_2(stack_a, stack_b, distance, r_distance_b);
}

void	solve(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	if (ft_lstsize(*stack_a) > 3 && !is_sorted(stack_a))
		pb(stack_a, stack_b);
	while (ft_lstsize(*stack_a) != 3 && !is_sorted(stack_a))
		solve_while_loop(stack_a, stack_b);
	if (!is_sorted(stack_a))
		solve_for_3(stack_a);
	//t_list *head = *stack_a;
	//t_list *head2 = *stack_b;
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
	while (ft_lstsize(*stack_b))
		sort_push_in_a(stack_a, stack_b);
	sort_a_after_push(stack_a);
}
