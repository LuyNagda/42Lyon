/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:02:00 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 21:46:23 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	while (i >= 0)
		free(args[i--]);
}

t_list	*initialize_stack(int argc, char **argv)
{
	t_list	*head;
	char	**args;
	int		i;

	i = 0;
	head = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		if (!head)
			head = ft_lstnew(ft_strict_atoi(args[i]));
		else
			ft_lstadd_back(&head, ft_lstnew(ft_strict_atoi(args[i])));
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (head);
}
