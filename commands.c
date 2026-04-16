/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:01:12 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/16 22:01:12 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*tmp;
	t_node	*tail;

	if (!a || !(*a)-> next)
		return ;
	tmp = *a;
	*a = (*a)-> next;
	tmp -> next = NULL;
	tail = *a;
	while (tail -> next)
		tail = tail -> next;
	tail -> next = tmp;
	ft_printf("ra\n");
}

void	rb(t_node	**b)
{
	t_node	*tmp;
	t_node	*tail;

	if (!*b || !(*b)-> next)
		return ;
	tmp = *b;
	*b = (*b)-> next;
	tmp -> next = NULL;
	tail = *b;
	while (tail->next)
		tail = tail->next;
	tail -> next = tmp;
	ft_printf("rb\n");
}

void	rrb(t_node	**b)
{
	t_node	*tmp;
	t_node	*prev;

	if (!*b || !(*b)-> next)
		return ;
	prev = *b;
	while (prev -> next -> next)
		prev = prev -> next;
	tmp = prev -> next;
	prev -> next = NULL;
	tmp -> next = *b;
	*b = tmp;
	ft_printf("rrb\n");
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)-> next;
	tmp -> next = *b;
	*b = tmp;
	ft_printf("pb\n");
}

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)-> next;
	tmp -> next = *a;
	*a = tmp;
	ft_printf("pa\n");
}
