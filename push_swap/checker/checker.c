/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:49:06 by luynagda          #+#    #+#             */
/*   Updated: 2023/12/03 11:47:54 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	do_commands_3(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "rra")))
	{
		reverse_rotate(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		reverse_rotate(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rrr")))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		return (0);
	}
	return (1);
}

int	do_commands_2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "pb")))
	{
		push(stack_b, stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		rotate(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		rotate(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rr")))
	{
		rotate(stack_a);
		rotate(stack_b);
		return (0);
	}
	return (do_commands_3(line, stack_a, stack_b));
	return (1);
}

int	do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
	{
		swap(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		swap(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		swap(stack_a);
		swap(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		push(stack_a, stack_b);
		return (0);
	}
	return (do_commands_2(line, stack_a, stack_b));
	return (1);
}

void	print_result(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a) && ft_lstsize(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_a)
		ft_lstclear(stack_a);
	if (stack_b)
		ft_lstclear(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	*line;

	if (argc > 1)
	{
		if (check_for_errors(argc, argv) == -1
			|| check_for_duplicates(argc, argv) == -1)
			return (-1);
		stack_a = initialize_stack(argc, argv);
		stack_b = NULL;
		while (get_next_line(0, &line) && line != NULL)
		{
			if (do_commands(line, &stack_a, &stack_b))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			free(line);
		}
		print_result(&stack_a, &stack_b);
	}
	return (0);
}
