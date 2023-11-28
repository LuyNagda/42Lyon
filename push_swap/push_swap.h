/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luynagda <luynagda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:28:25 by lunagda           #+#    #+#             */
/*   Updated: 2023/11/28 20:19:31 by luynagda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*ft_lstlast(t_list **lst);
t_list		*ft_lstnew(int content);
void		swap(t_list **h1);
void		push(t_list **h1, t_list **h2);
void		rotate(t_list **head);
void		reverse_rotate(t_list **head);
int			ft_lstsize(t_list *lst);
int			is_sorted(t_list **head);
long int	ft_strict_atoi(const char *str);
int			check_for_errors(int argc, char **argv);
int			check_for_duplicates(char **argv);
t_list		*initialize_stack(char **argv);
int			get_min(t_list **stack_a, int val);
void		solve_for_3(t_list **stack_a);
int			get_distance(t_list **stack_a, int content);
void		solve_for_4(t_list **stack_a, t_list **stack_b);
void		solve_for_5(t_list **stack_a, t_list **stack_b);
int			get_max(t_list **stack_a, int val);
void		solve(t_list **stack_a, t_list **stack_b);
int			get_cheapest(t_list **stack_a, t_list **stack_b);
int			to_find(t_list **stack_b, int val);
int			r_to_find(t_list **stack_a, int val);
void		both_stack_rotate(t_list **stack_a, t_list **stack_b,
				int distance, int distance_b);
void		both_stack_rev_rotate(t_list **stack_a, t_list **stack_b,
				int r_distance, int r_distance_b);
void		both_stack_different_1(t_list **stack_a, t_list **stack_b,
				int r_distance, int distance_b);
void		both_stack_different_2(t_list **stack_a, t_list **stack_b,
				int distance, int r_distance_b);
void		ft_lstclear(t_list **lst);
// rule functions
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);
int			ss(t_list **stack_a, t_list **stack_b);
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_a, t_list **stack_b);
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);

#endif	