/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:28:25 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/20 16:39:18 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
t_list	*swap(t_list *h1, t_list *h2);
void	push(t_list **h1, t_list **h2);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
int		ft_lstsize(t_list *lst);
int		is_sorted(t_list **head);

#endif