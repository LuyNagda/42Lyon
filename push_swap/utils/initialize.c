/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:02:00 by lunagda           #+#    #+#             */
/*   Updated: 2023/12/02 13:03:36 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(int argc, char **args)
{
	int	i;

	i = 0;
	if (argc != 2)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
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
	ft_free(argc, args);
	return (head);
}
