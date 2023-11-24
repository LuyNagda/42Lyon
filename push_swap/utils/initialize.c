/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:02:00 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/24 16:58:58 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*initialize_stack(char **argv)
{
	t_list	*head;
	int		i;

	i = 1;
	head = NULL;
	while (argv[i])
	{
		if (!head)
			head = ft_lstnew(ft_strict_atoi(argv[i]));
		else
			ft_lstadd_back(&head, ft_lstnew(ft_strict_atoi(argv[i])));
		i++;
	}
	return (head);
}
