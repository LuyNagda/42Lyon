/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:11:53 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/20 16:39:30 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a)
{
	t_list	*head;
	int		count;

	head = (*a);

	count = ft_lstsize(head);
	if (is_sorted(a) == -1)
	{
		
	}
}
